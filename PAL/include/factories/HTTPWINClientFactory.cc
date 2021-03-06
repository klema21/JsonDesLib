#include "HTTPClientFactory.h"
#include "../../HTTP/HTTPClient/WINHTTP.h"

std::shared_ptr<PAL::IHTTPClient> PAL::HTTPClientFactory::makeHTTPClient() {
	return std::make_shared<PAL::WINHTTP>();
}

std::function<std::shared_ptr<PAL::IHTTPClient>()> PAL::HTTPClientFactory::createHTTPClient = PAL::HTTPClientFactory::makeHTTPClient;
