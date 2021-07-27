#include "HTTPClientFactory.h"

std::shared_ptr<IHTTPClient> HTTPClientFactory::makeHTTPClient() {
	//return std::make_shared<CURLHTTP>();
	return std::make_shared<WINHTTP>();
}

std::function<std::shared_ptr<IHTTPClient>()> createHTTPClient = HTTPClientFactory::makeHTTPClient;