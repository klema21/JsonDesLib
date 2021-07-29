#ifndef IHTTPCLIENT_H
#define IHTTPCLIENT_H

#include "../../HTTP/HTTPClient/Request.h"
#include "../../HTTP/HTTPClient/Response.h"
#include <iostream>
#include <string>

namespace PAL {
	class IHTTPClient {
	public:
		virtual std::string sendRequest(Request&, Response&) = 0;
	};
}

#endif