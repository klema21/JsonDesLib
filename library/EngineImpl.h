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
#include <utility>

namespace JSDL {
	class EngineImpl : public IEngine {
		//std::lock_guard<std::mutex> lck(mtx);
		std::stack<std::reference_wrapper<ISerializable>> data{};

		// async containers
		std::vector<std::future<std::shared_ptr<PAL::IStream>>> asyncDes{};
		std::vector<std::reference_wrapper<ISerializable>> asyncData{};
		int i = 0;

		// super async containers
		std::queue<std::future<std::shared_ptr<PAL::IStream>>> asyncSuperData{};
		std::queue<std::reference_wrapper<ISerializable>> asyncDataSuper{};
		std::mutex mtx;

		// wild loop situation
		std::future<int> wildloop;
		//std::shared_ptr<PAL::IParser> parser_ = PAL::ParserFactory::createParser();
		int wildend;
	public:
		EngineImpl();
		~EngineImpl();
		void deserialize(const char* uri, ISerializable& d);
		void asyncUserDes(const char* uri, ISerializable& d, 
			std::function<void(JSDL::Status)> f);
		void asyncUserRst();
		int wild();
		void newValue( const std::string& name, std::string value);
		void newValue( const std::string& name, bool		value);
		void newValue( const std::string& name, int			value);
		void newValue( const std::string& name, double	    value);
		void newObject(const std::string& name);
		void endObject();
	};
}

#endif