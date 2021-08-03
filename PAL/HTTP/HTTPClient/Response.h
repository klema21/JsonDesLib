#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

namespace PAL {
	class Response {
	public:
		void setHeader(std::string& header) {
			m_header = header;
		}
		void setData(std::string& data) {
			m_data = data;
		}
		void setStatus(std::string& status) {
			m_status = status;
		}
		std::string getHeader() const {
			return m_header;
		}
		std::string getData() const {
			return m_data;
		}
		std::string getStatus() const {
			return m_status;
		}
		char getDData() const {
			return *data;
		}
	private:
		std::string m_header;
		std::string m_data;
		std::string m_status;
		char* data{ nullptr };
	};
}

#endif