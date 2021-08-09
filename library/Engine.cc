#include "Engine.h"
#include "../library/EngineImpl.h"

JSDL::EngineImpl holder;

/*void JSDL::Engine::deserialize(const char* uri, ISerializable& d) {
	holder.deserialize(uri, d);
}*/

JSDL::Status JSDL::Engine::deserialize(const char* uri, ISerializable& d) {
	return holder.deserialize(uri, d);
}

void JSDL::Engine::asyncDeserialize(const char* uri, ISerializable& d, callbackFunct callback){
	holder.asyncDeserialize(uri, d, callback);
}

void JSDL::Engine::asyncDeserializeRun() {
	holder.asyncDeserializeRun();
}