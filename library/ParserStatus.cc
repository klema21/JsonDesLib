#include "ParserStatus.h"

JSDL::ParserStatus::ParserStatus() {
	m_object_status = object_status::Empty;
}

void JSDL::ParserStatus::setObjectErrorStatus(const std::string& msg) {
	m_object_status = object_status::Error;
	m_msg += msg;
}

void JSDL::ParserStatus::setObjectCompleteStatus(const std::string& msg) {
	m_object_status = object_status::Complete;
	m_msg += msg;
}

std::string JSDL::ParserStatus::what() const {
	return m_msg;
}
