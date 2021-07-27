#ifndef IHTTPCLIENT_H
#define IHTTPCLIENT_H

#include "Request.h"
#include "Response.h"
#include <iostream>

class IHTTPClient {
public:
	virtual void sendRequest(Request&, Response&) = 0;
	//virtual void send(Request, Response, cb) = 0;
};

#endif