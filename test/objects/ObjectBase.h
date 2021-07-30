#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "../../include/ISerializable.h"


class ObjectBase : public JSDL::ISerializable {
public:
	virtual void setValue(const std::string& name, const std::string& value) {}
	virtual void setValue(const std::string& name, const bool& value) {}
	virtual void setValue(const std::string& name, const int& value) {}
	virtual void setValue(const std::string& name, const double& value) {}
	virtual JSDL::ISerializable& getObject(const std::string& name) { return *this; }
	virtual ~ObjectBase() {}
};

#endif