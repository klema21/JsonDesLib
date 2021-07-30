#ifndef TIMESTEP_H
#define TIMESTEP_H

#include "ObjectBase.h"

class Timestep : public ObjectBase {
	std::string absolute;
public:
	void Print() {
		std::cout << "absolute: " << absolute << std::endl;
	}
	void setValue(const std::string& name, const std::string& value) {
		if (name == "absolute") {
			absolute = value;
		}
	}
};

#endif