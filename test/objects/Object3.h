#ifndef OBJECT3_H
#define OBJECT3_H

#include "ObjectBase.h"
#include <string>

#include <iostream>
class Object3 : public ObjectBase {
	std::string ip;
public:
	/*~Object3() {
		puts("-------OBJ0-------");
		std::cout << "ip: " << ip << std::endl;
	}*/
	void setValue(const std::string& name, const std::string& value) {
		if (name == "date")
			ip = value;
	}
};

#endif