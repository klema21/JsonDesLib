#include "Status.h"

JSDL::Status::Status(const std::string& url) : m_url(url) {
	m_status = send_status::InProgress;
}

void JSDL::Status::set(const std::string& msg) {
	m_msg += msg;
}

std::string JSDL::Status::what() const {
	return m_msg;
}