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
		void sendRequest(Request& rq, Response& rs) {
			std::string foo = rq.getUrl();

			auto curl = curl_easy_init();
			if (curl) {
				curl_easy_setopt(curl, CURLOPT_URL, foo.c_str());
				std::string response_string;
				std::string header_string;
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
				curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

				char* url;
				long response_code;
				double elapsed;
				curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
				curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
				curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

				curl_easy_perform(curl);
				curl_easy_cleanup(curl);
				curl = nullptr;
				rs.setData(response_string);
				rs.setHeader(header_string);
			}
		}
	};
}

#endif