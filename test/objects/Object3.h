#ifndef OBJECT3_H
#define OBJECT3_H

#include "ObjectBase.h"
#include <string>

#include <iostream>
class Object3 : public ObjectBase {
	std::string ip;
public:
	std::string get() const {
		return ip;
	}

	void setValue(const std::string& name, const std::string& value) {
		if (name == "date")
			ip = value;
	}
};

#endif