#include "test/objects/Object3.h"
#include "include/Engine.h"
#include "library/Status.h"
#include <iostream>
#include <memory>

int main() {

	JSDL::Engine e;
	Object3 o;
	const char* test = "date.jsontest.com";
	JSDL::Status s = e.deserialize(test, o);
	std::cout << o.get() << std::endl;

	return 0;
}
