#include "EngineImpl.h"

JSDL::Status JSDL::EngineImpl::deserialize(const char* uri, ISerializable& object) {
	data.push(object);
	auto s = PAL::StreamFactory::createStream(uri);
	auto p = PAL::ParserFactory::createParser();
	std::weak_ptr<JSDL::EngineImpl> wself = shared_from_this();
	JSDL::Status fail_status;
	std::condition_variable cv;
	bool completed = false;
	JSDL::Status st = s->request(
		[&wself, &s, &fail_status, &completed, &cv](std::size_t size, JSDL::Status status) {
		if (auto self = wself.lock()) {
			std::unique_lock<std::mutex> lk(self->m);
			fail_status = status;
			if (status.m_status == JSDL::Status::send_status::Success &&
				status.m_http_status == JSDL::Status::http_status::OK) {
					completed = true;
					cv.notify_one();
			} else {
				cv.notify_one();
			}
		}
	});
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk);
	if (completed) {
		return p->parseStream(s, this);
	} else {
		fail_status.m_object_status = JSDL::Status::object_status::Error;
		return fail_status;
	}
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
