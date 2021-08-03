#ifndef STATUS_H
#define STATUS_H

#include <string>

namespace JSDL{
	class Status{
	public:
		Status(const std::string& url);
		void set(const std::string& msg);
		std::string what() const;

		enum class send_status {
			Success,
			Fail,
			InProgress,
			ConnectionError,
			Timeout
		} m_status;

	private:
		std::string m_msg{""};
		std::string m_url{};
	};
}

#endif