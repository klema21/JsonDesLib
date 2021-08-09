#ifndef ISTATUS_H
#define ISTATUS_H

namespace JSDL {
	class IStatus {
	public:
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
	};
}

#endif
