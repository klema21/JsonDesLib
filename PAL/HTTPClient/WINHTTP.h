#ifndef WINHTTP_H
#define WINHTTP_H

#include "IHTTPClient.h"
#include <algorithm>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
#pragma comment(lib,"ws2_32.lib")

namespace PAL {
	class WINHTTP : public IHTTPClient {
	public:
		void sendRequest(Request& rq, Response& rs) {
			get_Website(rq.getUrl());
			rs.setData(response_data);
			rs.setHeader(response_header);
		}

		void get_Website(std::string url) {
			get_http = "GET / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";

			if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
				std::cout << "WSAStartup failed.\n";
				system("pause");
				//return 1;
			}

			Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			host = gethostbyname(url.c_str());
			SockAddr.sin_port = htons(80);
			SockAddr.sin_family = AF_INET;
			SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

			if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
				std::cout << "Could not connect";
				system("pause");
				//return 1;
			}
			send(Socket, get_http.c_str(), strlen(get_http.c_str()), 0);

			int nDataLength = 0;
			while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
				int i = 0;
				while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r') {
					response_header += buffer[i];
					i += 1;
				}
				std::size_t found = response_header.find(cl);
				response_data = response_header;
				response_data.erase(0, found + 17);
				response_header.erase(found + 17, response_header.size());
			}
			closesocket(Socket);
			WSACleanup();
		}

	private:
		std::string response_data;
		std::string response_header;
		std::string cl = "Connection: close";
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
	};
}

#endif
