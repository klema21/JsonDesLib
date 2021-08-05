#ifndef CURLHTTP_H
#define CURLHTTP_H

#include "../../include/interfaces/IHTTPClient.h"
#include <curl/curl.h>

size_t writeFunction(void *ptr, 
	size_t size, 
	size_t nmemb, 
	std::string* data) {
	data->append((char*) ptr, size * nmemb);
	return size * nmemb;
}

namespace PAL {
	class CURLHTTP : public IHTTPClient {
	public:
		JSDL::Status sendRequest(Request& rq, Response& rs) {
			JSDL::Status foo(rq.getUrl());

			auto curl = curl_easy_init();
			if (curl) {
				curl_easy_setopt(curl, CURLOPT_URL, rq.getUrl().c_str());
				curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
				errbuf[0] = 0;
				std::string response_status;
				std::string response_header;
				std::string response_data;
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
				curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response_header);

				char* url;
				long response_code;
				double elapsed;
				curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
				curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
				curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

				//curl_easy_perform(curl);
				res = curl_easy_perform(curl);
				curl_easy_cleanup(curl);
				curl = nullptr;

				if(res != CURLE_OK){
					//m_status = errbuf;
					foo.set(errbuf);
					foo.m_status = JSDL::Status::send_status::ConnectionError;
				}

				response_status.assign(
					response_header, 0, response_header.find('\n'));
				response_header.erase(0, response_header.find('\n'));
				rs.setStatus(response_status);
				rs.setHeader(response_header);
				rs.setData(response_data);
				foo.m_status = JSDL::Status::send_status::Success;
				foo.set("Successful sending of data");
			}
			return foo;
		}
	private:
		CURLcode res;
		char errbuf[CURL_ERROR_SIZE];
	};
}

#endif
