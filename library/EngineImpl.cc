#include "EngineImpl.h"

void JSDL::EngineImpl::deserialize(const char* uri, ISerializable& object) {
	data.push(object);
	auto s = PAL::StreamFactory::createStream(uri, [](JSDL::Status result){
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
			if (result.m_http_status == JSDL::Status::http_status::ERROR)
				std::cout << result.statusCode() << std::endl;
			});
	if (s->available() != 0) {
		auto p = PAL::ParserFactory::createParser();
		p->parseStream(s, this);
	}
}

void JSDL::EngineImpl::asyncDeserialize(
	const char* uri, ISerializable& object, callbackFunct callback) {
	
	asyncQueueData.push(std::async([=]() {
		return PAL::StreamFactory::createStream(uri, callback);
	}));
	asyncQueueObjects.push(object);
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
