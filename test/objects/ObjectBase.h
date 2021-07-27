#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "../../include/ISerializable.h"


class ObjectBase : public ISerializable {
public:
	virtual void setValue(const std::string& name, std::string value) {}
	virtual void setValue(const std::string& name, bool value) {}
	virtual void setValue(const std::string& name, int value) {}
	virtual void setValue(const std::string& name, double value) {}
	virtual ISerializable& getObject(const std::string& name) { return *this; }
	virtual ~ObjectBase() {}
};

#endif