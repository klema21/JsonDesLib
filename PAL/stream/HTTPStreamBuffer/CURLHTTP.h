#ifndef CURLHTTP_H
#define CURLHTTP_H

#include "IHTTPClient.h"

class CURLHTTP : public IHTTPClient{
public:
	void sendRequest(Request& rq, Response& rs) {
		std::cout << "send linux data" << std::endl;
	}
};

#endif