#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include "IEngine.h"
#include "../include/ISerializable.h"
#include "../PAL/include/factories/ParserFactory.h"
#include "../PAL/include/factories/StreamFactory.h"
#include <stack>
#include <future>
#include <queue>

namespace JSDL {
	class EngineImpl : public IEngine {
	public:
		void deserialize	 (const char* uri, ISerializable& object);
		void asyncDeserialize(const char* uri, ISerializable& object, callbackFunct callback);
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
	};
}

#endif