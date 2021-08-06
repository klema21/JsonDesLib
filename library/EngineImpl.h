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
		std::stack<std::reference_wrapper<ISerializable>> data{};

		// super async containers
		std::queue<std::future<std::shared_ptr<PAL::IStream>>> asyncSuperData{};
		std::queue<std::reference_wrapper<ISerializable>> asyncDataSuper{};
		
	public:
		void deserialize(const char* uri, ISerializable& d);
		void asyncUserDes(const char* uri, ISerializable& d, callbackFunct callback);
		void asyncUserRst();
		void newValue( const std::string& name, std::string value);
		void newValue( const std::string& name, bool		value);
		void newValue( const std::string& name, int			value);
		void newValue( const std::string& name, double	    value);
		void newObject(const std::string& name);
		void endObject();
	};
}

#endif