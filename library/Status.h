#ifndef STATUS_H
#define STATUS_H

#include <string>

namespace JSDL{
	class Status{
	public:
		Status(const std::string& url);
		void setSendStatus(const std::string& msg);
		void setHTTPStatus(const std::string& status);
		std::string what() const;
		std::string statusCode() const;

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

	private:
		std::string m_msg{""};
		std::string m_url{};
		std::string m_http_response_status{};
	};
}

#endif