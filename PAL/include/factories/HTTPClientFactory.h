#ifndef HTTPCLIENTFACTORY_H
#define HTTPCLIENTFACTORY_H

#include <memory>
#include <functional>
#include "../interfaces/IHTTPClient.h"

namespace PAL {
	class HTTPClientFactory {
	public:
		static std::shared_ptr<PAL::IHTTPClient> makeHTTPClient();
		static std::function<std::shared_ptr<PAL::IHTTPClient>()> createHTTPClient;
	};
}

#endif
