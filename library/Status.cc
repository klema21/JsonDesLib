#include "Status.h"

JSDL::Status::Status(const std::string& url) : m_url(url) {
	m_status = send_status::InProgress;
	m_http_status = http_status::NO_STATUS;
}

void JSDL::Status::setSendStatus(const std::string& msg) {
	m_msg += msg;
}

void JSDL::Status::setHTTPStatus(const std::string& status) {
	m_http_response_status = status;
}

std::size_t JSDL::Status::bodySize() const {
	return m_body_size;
}

std::string JSDL::Status::what() const {
	return m_msg;
}