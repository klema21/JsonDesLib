#include "EngineImpl.h"

JSDL::EngineImpl::EngineImpl() {
	asyncD.reserve(10);
	rstData.reserve(10);
	//asyncDd.reserve(10);
	asyncRst.reserve(10);
}

void JSDL::EngineImpl::deserialize(const char* uri, ISerializable& d) {
	data.push(d);
	auto p = PAL::ParserFactory::createParser();
	auto s = PAL::StreamFactory::createStream(uri);
	p->parseStream(s, this);
}

void JSDL::EngineImpl::asyncUserDes(const char* uri, ISerializable& d) {
	if (i < 5) {
		asyncDd.push_back(std::async([&]() {
			return PAL::StreamFactory::createStream(uri);
		}));
		asyncData.push_back(d);
		++i;
	} else {
		for(int i = 0; i < 5; ++i) {
			data.push(asyncData[i]);
			auto p = PAL::ParserFactory::createParser();
			auto s = asyncDd[i].get();
			p->parseStream(s, this);
		}
	}
}

void JSDL::EngineImpl::asyncUserRst() {
	/*for (int i = 0; i < 4; ++i) {
		data.push(asyncData.front()); asyncData.pop();
		auto p = PAL::ParserFactory::createParser();
		auto s = asyncDd.front().get(); asyncDd.pop();
		p->parseStream(s, this);
	}*/
}

std::string JSDL::EngineImpl::asyncDes(const char* uri, ISerializable& d) {
	data.push(d);
	auto p = PAL::ParserFactory::createParser();
	auto s = PAL::StreamFactory::createStream(uri);
	p->parseStream(s, this);
	return "OK";
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
