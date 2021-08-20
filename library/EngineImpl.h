#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include "IEngine.h"
#include "../include/ISerializable.h"
#include "../PAL/include/factories/ParserFactory.h"
#include "../PAL/include/factories/StreamFactory.h"
#include "../library/Status.h"
#include "../library/ParserStatus.h"
#include <stack>
#include <future>
#include <condition_variable>
#include <mutex>
#include <queue>

namespace JSDL {
	class EngineImpl : public IEngine, public std::enable_shared_from_this<EngineImpl> {
	public:
		JSDL::Status deserialize (const char* uri, ISerializable& object);
		void asyncDeserialize	 (const char* uri, ISerializable& object, callbackFunct callback);
		void asyncDeserializeRun();
		void newValue( const std::string& name, std::string value);
		void newValue( const std::string& name, bool		value);
		void newValue( const std::string& name, int			value);
		void newValue( const std::string& name, double	    value);
		void newObject(const std::string& name);
		void endObject();
	private:
		std::stack<std::reference_wrapper<ISerializable>> data{};
		std::queue<std::future<std::shared_ptr<PAL::IStream>>> asyncQueueData{};
		std::queue<std::reference_wrapper<ISerializable>> asyncQueueObjects{};

		std::mutex m;

		JSDL::Status m_status;

		std::shared_ptr<EngineImpl> getptr() {
			//return shared_from_this();
			return std::shared_ptr<EngineImpl>(this);
		};

	};
}

#endif