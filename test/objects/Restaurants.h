#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include "ObjectBase.h"

class Restaurants : public ObjectBase {
	std::string location;
	std::string city_state;
	std::string phone;
public:
	void Print() {
		std::cout << "\t\t\t" << "location: " << location << std::endl;
		std::cout << "\t\t\t" << "city_state: " << city_state << std::endl;
		std::cout << "\t\t\t" << "phone: " << phone << std::endl;
		std::cout << "\n";
	}
	void setValue(const std::string& name, const std::string& value) {
		if (name == "location") {
			location = value;
		}
		if (name == "city_state") {
			city_state = value;
		}
		if (name == "phone") {
			phone = value;
		}
	}
};

#endif