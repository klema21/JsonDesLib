#include "Engine.h"
#include "../library/EngineImpl.h"


std::shared_ptr<JSDL::EngineImpl> holder = std::make_shared<JSDL::EngineImpl>();

JSDL::Status JSDL::Engine::deserialize(const char* uri, ISerializable& d) {
	return holder->deserialize(uri, d);
}

void JSDL::Engine::asyncDeserialize(const char* uri, ISerializable& d, callbackFunct callback){
	holder->asyncDeserialize(uri, d, callback);
}

void JSDL::Engine::asyncDeserializeRun() {
	holder->asyncDeserializeRun();
}