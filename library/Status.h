#ifndef STATUS_H
#define STATUS_H

#include <string>
#include "../include/IStatus.h"

namespace JSDL{
	class Status : public IStatus {
	public:
		Status();
		Status(const std::string& url);
		void setSendStatus(const std::string& msg);
		void setHTTPStatus(const std::string& status);
		void setObjectErrorStatus(const std::string& msg);
		void setObjectCompleteStatus(const std::string& msg);
		std::string what() const;
		std::string statusCode() const;
		std::string parserStatus() const;

		enum class send_status {
			Success,
			Fail,
			InProgress,
			ConnectionError
		} m_status;

		enum class http_status {
			NO_STATUS,
			OK,
			ERROR
		} m_http_status;

		enum class object_status {
			Empty,
			Complete,
			Error
		} m_object_status;
	private:
		std::string m_msg{};
		std::string m_url{};
		std::string m_http_response_status{};
		std::string m_parser_status{};
	};
}

#endif