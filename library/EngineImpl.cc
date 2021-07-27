#include "EngineImpl.h"

void EngineImpl::deserialize(const char* uri, ISerializable& d) {
	data.push(d);
	auto p = AbstractFactory::createParser();
	auto s = AbstractFactory::createStream(uri);
	p->parseStream(s, this);
}

void EngineImpl::newValue(const std::string& name, std::string value) {
	data.top().get().setValue(name, value);
}

void EngineImpl::newValue(const std::string& name, bool value) {
	data.top().get().setValue(name, value);
}

void EngineImpl::newValue(const std::string& name, int value) {
	data.top().get().setValue(name, value);
}

void EngineImpl::newValue(const std::string& name, double value) {
	data.top().get().setValue(name, value);
}

void EngineImpl::newObject(const std::string& name) {
	ISerializable& tmp = data.top().get().getObject(name);
	data.push(std::ref(tmp));
}

void EngineImpl::endObject() {
	data.pop();
}