#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
public:
	void setHeader(std::string header) {
		m_header = header;
	}
	void setUrl(const char* url) {
		m_url = url;
	}
	void setMethod(std::string method) {
		m_method = method;
	}
	std::string getHeader() {
		return m_header;
	}
	std::string getUrl() {
		return m_url;
	}
	std::string getMethod() {
		return m_method;
	}
private:
	std::string m_header;
	std::string m_url;
	std::string m_method;
};

#endif