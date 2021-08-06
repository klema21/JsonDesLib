#ifndef WINHTTP_H
#define WINHTTP_H

#include "../../include/interfaces/IHTTPClient.h"
#include <algorithm>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
#pragma comment(lib,"ws2_32.lib")

namespace PAL {
	class WINHTTP : public IHTTPClient {
	public:
		JSDL::Status sendRequest(Request& rq, Response& rs) {
			JSDL::Status m_status(rq.getUrl());
			get_Website(rq.getUrl(), rq.getMethod(), m_status);
			rs.setStatus(response_status);
			rs.setHeader(response_header);
			rs.setData(response_data);
			return m_status;
		}

		void get_Website(const std::string& url, const std::string& method, JSDL::Status& status) {
			get_http = method + " / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";

			if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
				status.setSendStatus("WSAStartup failed.\n");
				status.setSendStatus(std::system_category().message(WSAGetLastError()));
				status.m_status = JSDL::Status::send_status::Fail;
				return;
			}

			Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			host = gethostbyname(url.c_str());

			if (host == nullptr) {
				status.setSendStatus("Could not connect to " + url + ".\n");
				status.setSendStatus(std::system_category().message(WSAGetLastError()));
				status.m_status = JSDL::Status::send_status::ConnectionError;
				return;
			}
			SockAddr.sin_port = htons(80);
			SockAddr.sin_family = AF_INET;
			SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

			if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
				status.setSendStatus("Could not connect to " + url + ".\n");
				status.setSendStatus(std::system_category().message(WSAGetLastError()));
				status.m_status = JSDL::Status::send_status::ConnectionError;
				return;
			}
			send(Socket, get_http.c_str(), strlen(get_http.c_str()), 0);

			int nDataLength = 0;
			while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
				int i = 0;
				while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r') {
					response_header += buffer[i];
					i += 1;
				}
				response_status.assign(response_header, 0, response_header.find('\n'));
				response_header.erase(0, response_header.find('\n'));
				response_data.assign(response_header,
					response_header.find("\r\n\r\n"),
					response_header.size());
				response_header.erase(
					response_header.find("\r\n\r\n"),
					response_header.size());
			}
			if (WSAGetLastError()) {
				status.setSendStatus("Could not connect to " + url + ".\n");
				status.setSendStatus(std::system_category().message(WSAGetLastError()));
				status.m_status = JSDL::Status::send_status::ConnectionError;
				return;
			}
			closesocket(Socket);
			WSACleanup();
			status.setSendStatus("Successful sending of data.\n");
			status.setHTTPStatus(response_status);
			status.m_status = JSDL::Status::send_status::Success;
		}

	private:
		std::string response_data;
		std::string response_header;
		std::string response_status;
		std::locale local;
		char buffer[10000];
		int i = 0;
		WSADATA wsaData;
		SOCKET Socket;
		SOCKADDR_IN SockAddr;
		int lineCount = 0;
		int rowCount = 0;
		struct hostent *host;
		std::string get_http;
		std::string m_status;
	};
}

#endif
