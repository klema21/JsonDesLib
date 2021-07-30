#ifndef OBJECT_H
#define OBJECT_H

#include "ObjectBase.h"
#include "Timestep.h"
#include "Segment.h"

class Object : public ObjectBase {
	std::string assetGUID;
	std::string layer;
	int time;
	Timestep timestp;
	double duration;
	Segment segment;
public:
	~Object();
	void setValue(const std::string& name, const std::string& value);
	void setValue(const std::string& name, const int& value);
	void setValue(const std::string& name, const double& value);
	ISerializable& getObject(const std::string& name);
};

Object::~Object() {
	puts("-------OBJ1-------");
	std::cout << "assetGUID: " << assetGUID << std::endl;
	std::cout << "layer: " << layer << std::endl;
	std::cout << "time: " << time << std::endl;
	std::cout << "Tiemstep: "; timestp.Print();
	std::cout << "duration: " << duration << std::endl;
	std::cout << "Segment: "; segment.print();
}

void Object::setValue(const std::string& name, const std::string& value) {
	if (name == "assetGUID") {
		assetGUID = value;
	}
	if (name == "layer") {
		layer = value;
	}
}

void Object::setValue(const std::string& name, const int& value) {
	if (name == "time") {
		time = value;
	}
}

void Object::setValue(const std::string& name, const double& value) {
	if (name == "duration") {
		duration = value;
	}
}

JSDL::ISerializable& Object::getObject(const std::string& name) {
	if (name == "timestamp")
		return timestp;
	else if (name == "segment")
		return segment;
}

#endif