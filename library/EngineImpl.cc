#include "EngineImpl.h"

JSDL::EngineImpl::EngineImpl() {
	/*wildloop = std::async(std::launch::async, [=]() {
		return wild();
	});*/
	//auto wildl = std::async(wild, true);
}

JSDL::EngineImpl::~EngineImpl() {
	//wildend = wildloop.get();
	//++i;
	//std::cout << "dtor" << std::endl;
}

void JSDL::EngineImpl::deserialize(const char* uri, ISerializable& d) {
	data.push(d);
	auto p = PAL::ParserFactory::createParser();
	auto s = PAL::StreamFactory::createStream(uri, [](JSDL::Status result){
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test1" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
			});
	p->parseStream(s, this);
}

void JSDL::EngineImpl::asyncUserDes(const char* uri, ISerializable& d,
	std::function<void(JSDL::Status)> f) {
	
	asyncSuperData.push(std::async([=]() {
		return PAL::StreamFactory::createStream(uri, f);
	}));
	asyncDataSuper.push(d);
	//asyncUserRst();
}

void JSDL::EngineImpl::asyncUserRst() {
	while (!asyncSuperData.empty()) {
		data.push(asyncDataSuper.front());
		auto p = PAL::ParserFactory::createParser();
		auto s = asyncSuperData.front().get();
		p->parseStream(s, this);
		asyncDataSuper.pop();
		asyncSuperData.pop();
	}
}

int JSDL::EngineImpl::wild() {
	while (1) {
		//std::lock_guard<std::mutex> grd(mtx);
		asyncUserRst();
		/*while (!asyncSuperData.empty()) {
			std::cout << "Here i am" << std::endl;
			data.push(asyncDataSuper.front());
			auto s = asyncSuperData.front().get();
			//p->parseStream(s, this);
			asyncDataSuper.pop();
			asyncSuperData.pop();
		}*/
	}
}

void JSDL::EngineImpl::newValue(const std::string& name, std::string value) {
	data.top().get().setValue(name, value);
}

void JSDL::EngineImpl::newValue(const std::string& name, bool value) {
	data.top().get().setValue(name, value);
}

void JSDL::EngineImpl::newValue(const std::string& name, int value) {
	data.top().get().setValue(name, value);
}

void JSDL::EngineImpl::newValue(const std::string& name, double value) {
	data.top().get().setValue(name, value);
}

void JSDL::EngineImpl::newObject(const std::string& name) {
	ISerializable& tmp = data.top().get().getObject(name);
	data.push(std::ref(tmp));
}

void JSDL::EngineImpl::endObject() {
	data.pop();
}
