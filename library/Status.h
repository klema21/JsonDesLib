#ifndef STATUS_H
#define STATUS_H

#include <string>

namespace JSDL{
	class Status {
	public:
		Status(const std::string& url);
		void set(const std::string& msg);
		std::string what() const;
	private:
		std::string m_msg{""};
		std::string m_url{};
		enum class send_status {
			Success,
			Fail,
			InProgress
		} m_status;
	};
}

#endif