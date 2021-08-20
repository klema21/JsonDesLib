#include "HTTPStreamBuffer.h"

PAL::HTTPStreamBuffer::HTTPStreamBuffer(const char* src) {
	m_rqst.setUrl(src);
}

JSDL::Status PAL::HTTPStreamBuffer::request(std::function<void(std::size_t, JSDL::Status)> callback) {
	threadOb = new std::thread([&, callback]() {
		auto client = HTTPClientFactory::createHTTPClient();
		auto status = client->sendRequest(m_rqst, m_rsp);

		if (status.m_status == JSDL::Status::send_status::Success &&
			status.m_http_status == JSDL::Status::http_status::OK) {

			m_size = m_rsp.getData().size();
			m_buff = new char[m_size];
			std::string tmp = m_rsp.getData();
			std::copy(tmp.begin(), tmp.end(), m_buff);
		}
		if (callback != nullptr) {
			callback(m_size, status);
		}
	});
	return _status;
}

PAL::HTTPStreamBuffer::~HTTPStreamBuffer() {
	threadOb->join();
	delete threadOb;
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
	callback(m_size);
	return m_size;
}

std::size_t PAL::HTTPStreamBuffer::total() const {
	return m_size;
}

std::size_t PAL::HTTPStreamBuffer::getData(std::size_t data) {
	return data;
}

JSDL::Status PAL::HTTPStreamBuffer::getStatus() const {
	return _status;
}
