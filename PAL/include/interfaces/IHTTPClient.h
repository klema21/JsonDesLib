#ifndef IHTTPCLIENT_H
#define IHTTPCLIENT_H

#include "../../HTTP/HTTPClient/Request.h"
#include "../../HTTP/HTTPClient/Response.h"
#include "../../../library/Status.h"
#include <iostream>
#include <string>

namespace PAL {
	class IHTTPClient {
	public:
		virtual JSDL::Status sendRequest(Request&, Response&) = 0;
	};
}

#endif
