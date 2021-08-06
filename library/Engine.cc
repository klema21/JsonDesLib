#include "Engine.h"
#include "../library/EngineImpl.h"

JSDL::EngineImpl holder;

void JSDL::Engine::deserialize(const char* uri, ISerializable& d) {
	holder.deserialize(uri, d);
}

void JSDL::Engine::asyncDes(const char* uri, ISerializable& d, callbackFunct callback){
	holder.asyncUserDes(uri, d, callback);
}

void JSDL::Engine::asyncUserRst() {
	holder.asyncUserRst();
}