#include "HTTPClientFactory.h"
#include "CURLHTTP.h"

std::shared_ptr<PAL::IHTTPClient> PAL::HTTPClientFactory::makeHTTPClient() {
	return std::make_shared<PAL::CURLHTTP>();
}

std::function<std::shared_ptr<PAL::IHTTPClient>()> createHTTPClient = PAL::HTTPClientFactory::makeHTTPClient;
