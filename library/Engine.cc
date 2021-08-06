#include "Engine.h"
#include "../library/EngineImpl.h"

JSDL::EngineImpl holder;

void JSDL::Engine::deserialize(const char* uri, ISerializable& d) {
	holder.deserialize(uri, d);
}

void JSDL::Engine::asyncDes(const char* uri, ISerializable& d, 
	std::function<void(JSDL::Status)> f) {

	holder.asyncUserDes(uri, d, f);
}

void JSDL::Engine::asyncUserRst() {
	holder.asyncUserRst();
}