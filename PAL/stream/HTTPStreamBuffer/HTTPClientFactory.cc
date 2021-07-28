#include "HTTPClientFactory.h"
#include "CURLHTTP.h"

std::shared_ptr<IHTTPClient> HTTPClientFactory::makeHTTPClient() {
	return std::make_shared<CURLHTTP>();
}

std::function<std::shared_ptr<IHTTPClient>()> createHTTPClient = HTTPClientFactory::makeHTTPClient;
