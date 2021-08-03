#include "EngineImpl.h"

JSDL::EngineImpl::EngineImpl() {
	
}

void JSDL::EngineImpl::deserialize(const char* uri, ISerializable& d) {
	std::cout << "No longer available, use async slow man" << std::endl;
	/*data.push(d);
	auto p = PAL::ParserFactory::createParser();
	auto s = PAL::StreamFactory::createStream(uri);
	p->parseStream(s, this);*/
}

void JSDL::EngineImpl::asyncUserDes(const char* uri, ISerializable& d,
	std::function<void(JSDL::Status)> f) {
	/*if (i < 5) {
		asyncDes.push_back(std::async([&]() {
			return PAL::StreamFactory::createStream(uri);
		}));
		asyncData.push_back(d);
		++i;
	} else {
		for(int i = 0; i < 5; ++i) {
			data.push(asyncData[i]);
			auto p = PAL::ParserFactory::createParser();
			auto s = asyncDes[i].get();
			p->parseStream(s, this);
		}
	}*/

	/*asyncSuperData.push(std::async([=]() {
		return PAL::StreamFactory::createStream(uri, f);
		
	}));
	asyncDataSuper.push(d);*/

	auto s = std::async(PAL::StreamFactory::createStream, uri, f);

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
