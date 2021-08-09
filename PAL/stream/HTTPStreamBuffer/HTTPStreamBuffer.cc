#include "HTTPStreamBuffer.h"

PAL::HTTPStreamBuffer::HTTPStreamBuffer(const char* src) {
	m_rqst.setUrl(src);
	/*auto client = HTTPClientFactory::createHTTPClient();

	af = std::async(std::launch::async, [=]() {
		return client->sendRequest(m_rqst, m_rsp);
	});
	status = af.get();

	if (status.m_status == JSDL::Status::send_status::Success &&
		status.m_http_status == JSDL::Status::http_status::OK) {
		m_size = m_rsp.getData().size();
		m_buff = new char[m_size];
		std::string tmp = m_rsp.getData();
		std::copy(tmp.begin(), tmp.end(), m_buff);
	}*/
	/*if (m_callback != nullptr) {
		m_callback(m_size);
	}*/
}

JSDL::Status PAL::HTTPStreamBuffer::request(std::function<void(std::size_t)> callback, std::weak_ptr<PAL::IStream> obj) {
	std::mutex m;
	std::condition_variable cv;
	std::thread threadObj([&]() {
		std::unique_lock<std::mutex> lk(m);
		auto client = HTTPClientFactory::createHTTPClient();
		status = client->sendRequest(m_rqst, m_rsp);
		if (status.m_status == JSDL::Status::send_status::Success &&
			status.m_http_status == JSDL::Status::http_status::OK) {
			m_size = m_rsp.getData().size();
			m_buff = new char[m_size];
			std::string tmp = m_rsp.getData();
			std::copy(tmp.begin(), tmp.end(), m_buff);
		}
		if (callback != nullptr) {
			callback(m_size);
		}
		if (auto spt = obj.lock()) {
			
		} else {
			return status;
		}
		lk.unlock();
		cv.notify_one();
	});
	
	//threadObj.join();
	return status;
}

PAL::HTTPStreamBuffer::~HTTPStreamBuffer() {
	delete[] m_buff;
}

std::size_t PAL::HTTPStreamBuffer::read(uint8_t* dst, size_t size) {
	if (m_curr < m_size) {
		auto length = (m_curr + size) < m_size ? m_curr + size : m_size;
		std::copy(m_buff + m_curr, m_buff + length, dst + m_curr);
		m_curr = length;
		return length;
	}
	return 0;
}

void PAL::HTTPStreamBuffer::reset() {
	m_curr = 0;
}

std::size_t PAL::HTTPStreamBuffer::available() const {
	return m_size - m_curr;
}

std::size_t PAL::HTTPStreamBuffer::_available(std::function<void(std::size_t size)> callback) const {
	/*if (m_size > 0) {
		callback(m_size);
	}*/
	//m_callback = callback(m_size);
	callback(m_size);
	return m_size;
}

std::size_t PAL::HTTPStreamBuffer::total() const {
	return m_size;
}

JSDL::Status PAL::HTTPStreamBuffer::getStatus() const {
	return status;
}
