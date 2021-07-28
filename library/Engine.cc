#include "Engine.h"
#include "../library/EngineImpl.h"
#include "ISerializable.h"

JSDL::EngineImpl holder;

void JSDL::Engine::deserialize(const char* uri, ISerializable& d) {
	holder.deserialize(uri, d);
}