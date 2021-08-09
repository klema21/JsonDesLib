#include "EngineImpl.h"

JSDL::Status JSDL::EngineImpl::deserialize(const char* uri, ISerializable& object) {
	data.push(object);
	auto s = PAL::StreamFactory::createStream(uri);
	auto p = PAL::ParserFactory::createParser();
	JSDL::Status st;
	std::weak_ptr<PAL::IStream> gw = s;
	//std::weak_ptr<s.get()> sl;
	s->request([&](std::size_t size) {
		st = p->parseStream(s, this);
	}, gw);
	return st;
}

void JSDL::EngineImpl::asyncDeserialize(
	const char* uri, ISerializable& object, callbackFunct callback) {
	
	/*asyncQueueData.push(std::async([=]() {
		return PAL::StreamFactory::createStream(uri, callback);
	}));
	asyncQueueObjects.push(object);*/
}

void JSDL::EngineImpl::asyncDeserializeRun() {
	while (!asyncQueueData.empty()) {
		data.push(asyncQueueObjects.front());
		auto s = asyncQueueData.front().get();
		if (s->available() != 0) {
			auto p = PAL::ParserFactory::createParser();
			p->parseStream(s, this);
		}
		asyncQueueData.pop();
		asyncQueueObjects.pop();
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
