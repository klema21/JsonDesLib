#ifndef HTTPSTREAMBUFFER_H
#define HTTPSTREAMBUFFER_H

#include "../../../PAL/include/interfaces/IStream.h"
#include "../../include/interfaces/IHTTPClient.h"
#include "../../include/factories/HTTPClientFactory.h"
#include "../../HTTP/HTTPClient/Request.h"
#include "../../HTTP/HTTPClient/Response.h"
#include "../../../library/Status.h"
#include <algorithm>
#include <future>
#include <queue>
#include <thread>
#include <condition_variable>

typedef std::function<void(JSDL::Status)> callbackFunct;

namespace PAL {
	class HTTPStreamBuffer : public PAL::IStream {
	public:
		HTTPStreamBuffer(const char* src);
		~HTTPStreamBuffer();

		std::size_t read(uint8_t* dst, size_t size);
		void reset();
		std::size_t available() const;
		std::size_t total() const;
		std::size_t getData(std::size_t data);
		JSDL::Status getStatus() const;

		JSDL::Status request(std::function<void(std::size_t, JSDL::Status)> callback);
		std::size_t _available(std::function<void(std::size_t size)> callback) const;
	private:
		std::size_t m_size{ 0 };
		std::size_t m_curr{ 0 };
		char* m_buff{ nullptr };
		char* rsp_buff{ nullptr };
		Request m_rqst;
		Response m_rsp;
		JSDL::Status _status;
		std::future<JSDL::Status> af;
		std::function<void(std::size_t)> m_callback = nullptr;

		std::condition_variable cv;
		std::thread *threadOb = nullptr;

		std::queue<std::future<JSDL::Status>> d;
		std::queue<JSDL::Status> q;
	};
}

#endif