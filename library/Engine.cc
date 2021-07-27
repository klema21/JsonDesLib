#include "Engine.h"
#include "../library/EngineImpl.h"
#include "ISerializable.h"

EngineImpl holder;

void Engine::deserialize(const char* uri, ISerializable& d) {
	holder.deserialize(uri, d);
}