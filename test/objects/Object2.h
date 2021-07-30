#ifndef OBJECT2_H
#define OBJECT2_H

#include "ObjectBase.h"
#include <ios>

class Object2 : public ObjectBase {
	std::string project;
	bool active = false;
public:
	~Object2();
	void setValue(const std::string& name, const std::string& value);
	void setValue(const std::string& name, const bool& value);
};

Object2::~Object2() {
	puts("-------OBJ2-------");
	std::cout << "project: " << project << std::endl;
	if(active)
		std::cout << "active: " << std::boolalpha << active << std::endl;
	else
		std::cout << "active: " << std::noboolalpha << active << std::endl;
}

void Object2::setValue(const std::string& name, const std::string& value) {
	if (name == "project") {
		project = value;
	}
}

void Object2::setValue(const std::string& name, const bool& value) {
	if (name == "active")
		active = value;
}

#endif