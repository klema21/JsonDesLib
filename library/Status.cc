#include "Status.h"

JSDL::Status::Status() {

}

JSDL::Status::Status(const std::string& url) : m_url(url) {
	m_status = send_status::InProgress;
	m_http_status = http_status::NO_STATUS;
	m_object_status = object_status::Empty;
}

void JSDL::Status::setSendStatus(const std::string& msg) {
	m_msg += msg;
}

void JSDL::Status::setHTTPStatus(const std::string& status) {
	m_http_response_status = status;
	if (m_http_response_status == "HTTP/1.1 200 OK\r") {
		m_http_status = http_status::OK;
	}
	else {
		m_http_status = http_status::ERROR;
	}
}

void JSDL::Status::setObjectErrorStatus(const std::string& msg) {
	m_object_status = object_status::Error;
	m_parser_status += msg;
}

void JSDL::Status::setObjectCompleteStatus(const std::string& msg) {
	m_object_status = object_status::Complete;
	m_parser_status += msg;
}

std::string JSDL::Status::what() const {
	return m_msg;
}

std::string JSDL::Status::statusCode() const {
	return m_http_response_status;
}

std::string JSDL::Status::parserStatus() const {
	return m_parser_status;
}