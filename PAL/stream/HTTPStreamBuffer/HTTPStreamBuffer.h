#ifndef HTTPSTREAMBUFFER_H
#define HTTPSTREAMBUFFER_H

#include "../../../PAL/include/interfaces/IStream.h"
#include "../../include/interfaces/IHTTPClient.h"
#include "../../HTTP/HTTPClient/HTTPClientFactory.h"
#include "../../HTTP/HTTPClient/Request.h"
#include "../../HTTP/HTTPClient/Response.h"
#include <algorithm>

typedef std::function<int(int)> callbackFunct;

namespace PAL {
	class HTTPStreamBuffer : public PAL::IStream {
	public:
		HTTPStreamBuffer(const char* src);
		HTTPStreamBuffer(const char* src, std::size_t size);
		~HTTPStreamBuffer();

		std::size_t read(uint8_t* dst, size_t size);
		void reset();
		std::size_t available() const;
		std::size_t total() const;

	private:
		std::size_t m_size{ 0 };
		std::size_t m_curr{ 0 };
		char* m_buff{ nullptr };
		Request m_rqst;
		Response m_rsp;
		callbackFunct f;
	};
}

#endif