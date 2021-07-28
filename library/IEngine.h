#ifndef IENGINE_H
#define IENGINE_H

#include <iostream>

namespace JSDL {
	class IEngine {
	public:
		virtual void newValue(const std::string& name, std::string value) = 0;
		virtual void newValue(const std::string& name, bool value)		  = 0;
		virtual void newValue(const std::string& name, int value)		  = 0;
		virtual void newValue(const std::string&, double value)			  = 0;
		virtual void newObject(const std::string& name)					  = 0;
		virtual void endObject()										  = 0;
		virtual ~IEngine() {}
	};
}

#endif