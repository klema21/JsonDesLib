#ifndef TESTRUNNER_H
#define TESTRUNNET_H

#include "objects/Object.h"
#include "objects/Object2.h"
#include "objects/Object3.h"
#include "Engine.h"
#include <fstream>

class TestRunner {
public:
	void runVisualTests() const;
};

void TestRunner::runVisualTests() const {
	Engine e;
	// Test - 0 ----------------------------------------------------------------
	// Big obj fills with big file
	const char* test0 = "ip.jsontest.com";
	Object3 ob0;
	e.deserialize(test0, ob0);
	// Test - 1 ----------------------------------------------------------------
	Object3 ob1;
	e.deserialize(test0, ob1);
	// Test - 2 ----------------------------------------------------------------
	Object3 ob2;
	e.deserialize(test0, ob2);
	// Test - 3 ----------------------------------------------------------------
	Object3 ob3;
	e.deserialize(test0, ob3);
	// Test - 4 ----------------------------------------------------------------
	Object3 ob4;
	e.deserialize(test0, ob4);
	// Test - 5 ----------------------------------------------------------------
	Object3 ob5;
	e.deserialize(test0, ob5);
	// Test - 1 ----------------------------------------------------------------
	// Big obj fills with big file
	/*std::string line, text;
	std::ifstream in("./test/testData/test1.json");
	while (std::getline(in, line)) {
		text += line + "\n";
	}
	const char* test1 = text.c_str();
	Object ob1;
	e.deserialize(test1, ob1);
	//// Test - 2 ----------------------------------------------------------------
	//// Small obj fills with small file
	const char* test2 = "{\"project\":\"json\",\"active\": true }";
	Object2 ob2;
	e.deserialize(test2, ob2);
	//// Test - 3 ----------------------------------------------------------------
	//// Small obj fill one field from big file
	std::string line3, text3;
	std::ifstream in3("./test/testData/test3.json");
	while (std::getline(in3, line3)) {
		text3 += line3 + "\n";
	}
	const char* test3 = text3.c_str();
	Object2 ob3;
	e.deserialize(test3, ob3);
	//// Test - 4 ----------------------------------------------------------------
	//// Small obj fills with empty const char*
	const char* test4 = "";
	Object2 ob4;
	e.deserialize(test4, ob4);
	//// Test - 5 ----------------------------------------------------------------
	//// Small obj fills with empty file
	std::string line5, text5;
	std::ifstream in5("./test/testData/test5.json");
	while (std::getline(in5, line5)) {
		text5 += line5 + "\n";
	}
	const char* test5 = text5.c_str();
	Object2 ob5;
	e.deserialize(test5, ob5);
	//// Test - 6 ----------------------------------------------------------------
	//// Big obj fills with small file
	const char* test6 = "{\"assetGUID\":\"foo\",\"layer\":\"bar\"}";
	Object ob6;
	e.deserialize(test6, ob6);*/
}

#endif // !TESTRUNNER_H