#ifndef ENGINEIMPL_H
#define ENGINEIMPL_H

#include "IEngine.h"
#include "../include/ISerializable.h"
#include "../PAL/include/AbstractFactory.h"
#include <stack>

namespace JSDL {
	class EngineImpl : public IEngine {
		std::stack<std::reference_wrapper<ISerializable>> data{};
	public:
		void deserialize(const char* uri, ISerializable& d);
		void newValue(const std::string& name, std::string value);
		void newValue(const std::string& name, bool value);
		void newValue(const std::string& name, int value);
		void newValue(const std::string& name, double value);
		void newObject(const std::string& name);
		void endObject();
	};
}

#endif