#pragma once

#include <string>

namespace JSDL {
	class ParserStatus {
	public:
		ParserStatus();
		void setObjectErrorStatus(const std::string& msg);
		void setObjectCompleteStatus(const std::string& msg);
		std::string what() const;
		enum class object_status {
			Empty,
			Complete,
			Error
		} m_object_status;
	private:
		std::string m_msg{};
	};
}