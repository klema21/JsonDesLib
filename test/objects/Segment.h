#ifndef SEGMENT_H
#define SEGMENT_H

#include <vector>

#include "ObjectBase.h"
#include "legacyIds.h"
#include "Restaurants.h"

class Segment : public ObjectBase {
	std::string segmentGUID;
	legacyIds legacy;
	std::vector<Restaurants> restaurant;
	std::vector<int> restaurants;
	std::string segmentType;
	std::string shortDescription;
	std::string longDescription;
public:
	void print() {
		std::cout << "segmentGUID: " << segmentGUID << std::endl;
		std::cout << "	 legacyIds: "; legacy.Print();
		std::cout << "	 restaurants: "; 
		for (auto r : restaurants)
			std::cout << r << " "; std::cout << "\n";
		std::cout << "	 restaurant: " << std::endl;
		for (auto r : restaurant)
			r.Print();
		std::cout << std::endl;
		std::cout << " 	 segmentType: " << segmentType << std::endl;
		std::cout << "	 shortDescription: " << shortDescription << std::endl;
		std::cout << "	 longDescription: " << longDescription << std::endl;
	}
	void setValue(const std::string& name, std::string value) {
		if (name == "segmentGUID") {
			segmentGUID = value;
		}
		if (name == "segmentType") {
			segmentType = value;
		}
		if (name == "shortDescription") {
			shortDescription = value;
		}
		if (name == "longDescription") {
			longDescription = value;
		}
	}

	void setValue(const std::string& name, int value) {
		if (name == "restaurants") {
			restaurants.push_back(value);
		}
	}

	JSDL::ISerializable& getObject(const std::string& name) {
		if (name == "legacyIds") {
			return legacy;
		}
		if (name == "restaurant") {
			Restaurants r;
			restaurant.push_back(r);
			return restaurant.back();
		}
	}
};

#endif