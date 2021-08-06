#include "HTTPStreamBuffer.h"

PAL::HTTPStreamBuffer::HTTPStreamBuffer(const char* src, callbackFunct callback){

	m_rqst.setUrl(src);
	auto client = HTTPClientFactory::createHTTPClient();
	JSDL::Status status = client->sendRequest(m_rqst, m_rsp);

	if (status.m_status == JSDL::Status::send_status::Success &&
	status.m_http_status == JSDL::Status::http_status::OK) {
		m_size = m_rsp.getData().size();
		m_buff = new char[m_size];
		std::string tmp = m_rsp.getData();
		std::copy(tmp.begin(), tmp.end(), m_buff);
	}
	callback(status);
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

std::size_t PAL::HTTPStreamBuffer::total() const {
	return m_size;
}
