#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include "IEngine.h"
#include "../include/ISerializable.h"
#include "../PAL/include/factories/ParserFactory.h"
#include "../PAL/include/factories/StreamFactory.h"
#include <stack>


#include <thread>
#include <future>
#include <vector>
#include <queue>
#include <mutex>

namespace JSDL {
	class EngineImpl : public IEngine {
		std::stack<std::reference_wrapper<ISerializable>> data{};

		// async containers
		std::vector<std::future<std::string>> asyncD{};
		std::vector<std::future<std::shared_ptr<PAL::IStream>>> asyncDd{};
		std::vector<std::reference_wrapper<ISerializable>> asyncData{};
		std::vector<std::shared_ptr<PAL::IStream>> asyncRst{};
		std::vector<std::string> rstData{};
		int i = 0;
	public:
		EngineImpl();
		void deserialize(const char* uri, ISerializable& d);
		void asyncUserDes(const char* uri, ISerializable& d);
		void asyncUserRst();
		std::string asyncDes(const char* uri, ISerializable& d);
		void newValue( const std::string& name, std::string value);
		void newValue( const std::string& name, bool value);
		void newValue( const std::string& name, int value);
		void newValue( const std::string& name, double value);
		void newObject(const std::string& name);
		void endObject();
	};
}

#endif