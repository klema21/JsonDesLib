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
		std::string sendRequest(Request& rq, Response& rs) {
			get_Website(rq.getUrl(), rq.getMethod());
			rs.setStatus(response_status);
			rs.setHeader(response_header);
			rs.setData(response_data);
			return m_status;
		}

		void get_Website(const std::string& url, const std::string& method ) {
			get_http = method + " / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";

			if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
				m_status += "WSAStartup failed.\n";
				m_status += std::system_category().message(WSAGetLastError());
				return;
			}

			Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			host = gethostbyname(url.c_str());

			if (host == nullptr) {
				m_status += "Could not connect to " + url + ".\n";
				m_status += std::system_category().message(WSAGetLastError());
				return;
			}
			SockAddr.sin_port = htons(80);
			SockAddr.sin_family = AF_INET;
			SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

			if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
				m_status += "Could not connect to " + url + ".\n";
				m_status += std::system_category().message(WSAGetLastError());
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
				m_status += "Could not connect to " + url + ".\n";
				m_status += std::system_category().message(WSAGetLastError());
				return;
			}
			closesocket(Socket);
			WSACleanup();
			m_status += "Successful sending of data";
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
