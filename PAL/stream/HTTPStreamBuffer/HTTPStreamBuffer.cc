#include "HTTPStreamBuffer.h"

PAL::HTTPStreamBuffer::HTTPStreamBuffer(const char* src) {
	m_rqst.setUrl(src);
	auto p = HTTPClientFactory::createHTTPClient();
	std::string status = p->sendRequest(m_rqst, m_rsp);
	if(status != "Successful sending of data")
		std::cout << status << std::endl;
	std::cout << m_rsp.getStatus() << std::endl;
	m_size = m_rsp.getData().size();
	m_buff = new char[m_size];
	std::string tmp = m_rsp.getData();
	std::copy(tmp.begin(), tmp.end(), m_buff);
}

PAL::HTTPStreamBuffer::HTTPStreamBuffer(const char* src, std::size_t size) {

}

PAL::HTTPStreamBuffer::~HTTPStreamBuffer() {
	delete m_buff;
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
