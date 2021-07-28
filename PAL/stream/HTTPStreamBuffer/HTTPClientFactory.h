#ifndef HTTPCLIENTFACTORY_H
#define HTTPCLIENTFACTORY_H

#include <memory>
#include <functional>
#include "IHTTPClient.h"

class HTTPClientFactory {
public:
	static std::shared_ptr<IHTTPClient> makeHTTPClient();
	static std::function<std::shared_ptr<IHTTPClient>> createHTTPClient;
};

#endif
