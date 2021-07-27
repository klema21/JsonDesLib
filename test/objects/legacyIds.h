#ifndef LEGACYIDS_H
#define LEGACYIDS_H

#include "ObjectBase.h"

class legacyIds : public ObjectBase {
	std::string shortId;
public:
	void Print() {
		std::cout << "shortId: " << shortId << std::endl;
	}
	void setValue(const std::string& name, std::string value) {
		if (name == "shortId") {
			shortId = value;
		}
	}
};

#endif