#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include "objects/Object.h"
#include "objects/Object2.h"
#include "objects/Object3.h"
#include "Engine.h"
#include "../library/Status.h"
#include "Timer.h"
#include <chrono>
#include <functional>

using namespace std::chrono;
class TestRunner {
public:
	std::string runGTest() const {
		return "08-05-2021";
	}

	void runVisualTests() const {
		JSDL::Engine e;
		// Test - 0 ----------------------------------------------------------------
		// Big obj fills with big file
		//const char* test0 = "ip.jsontest.com";
		const char* test10 = "date.jsontest.com";
		//const char* test0 = "linkedin.com";
		//const char* test0 = "vk.com";
		//const char* test0 = "rkn.gov.ru";
		//const char* test0 = "example.com";
		//const char* test0 = "abc";

		for (int i = 0; i < 10; ++i) {
			Object3 ob0;
			//e.onResult([&](Result res) {if (res) {} esle {}});
			e.deserialize(test10, ob0);
			std::cout << ob0.get() << std::endl;
		}

		Object3 ob0;
		const char* test0 = "date.jsontest.com";
		
		e.asyncDes(test0, ob0, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test0" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob1;
		const char* test1 = "date.jsontest.com";

		e.asyncDes(test1, ob1, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test1" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob2;
		const char* test2 = "date.jsontest.com";

		e.asyncDes(test2, ob2, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test2" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob3;
		const char* test3 = "date.jsontest.com";

		e.asyncDes(test3, ob3, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test3" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob4;
		const char* test4 = "date.jsontest.com";

		e.asyncDes(test4, ob4, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test4" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob5;
		const char* test5 = "date.jsontest.com";

		e.asyncDes(test5, ob5, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test5" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob6;
		const char* test6 = "date.jsontest.com";

		e.asyncDes(test6, ob6, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test6" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob7;
		const char* test7 = "date.jsontest.com";

		e.asyncDes(test7, ob7, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test7" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob8;
		const char* test8 = "date.jsontest.com";

		e.asyncDes(test8, ob8, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test8" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});

		Object3 ob9;
		const char* test9 = "date.jsontest.com";

		e.asyncDes(test9, ob9, [](JSDL::Status result) {
			if (result.m_status == JSDL::Status::send_status::Success)
				std::cout << "test9" << std::endl;
			if (result.m_status == JSDL::Status::send_status::ConnectionError)
				std::cout << result.what() << std::endl;
		});
		
		e.asyncUserRst();
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
};

#endif // !TESTRUNNER_H
