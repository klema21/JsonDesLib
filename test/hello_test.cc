#include "Engine.h"
#include "objects/Object3.h"
#include <gtest/gtest.h>
#include <string>
#include "TestRunner.h"

TEST(SyncTest, GoodRequest__SuitableObject__10) {
	JSDL::Engine e;
	const char* test0 = "date.jsontest.com";
	for (int i = 0; i < 10; ++i) {
		Object3 ob0;
		e.deserialize(test0, ob0);
		EXPECT_STREQ(ob0.get().c_str(), "08-05-2021");
	}
}

TEST(SyncTest , GoodRequest__InappropriateObject__10) {
	JSDL::Engine e;
	const char* test0 = "ip.jsontest.com";
	for (int i = 0; i < 10; ++i) {
		Object3 ob0;
		e.deserialize(test0, ob0);
		EXPECT_STREQ(ob0.get().c_str(), "");
	}
}

TEST(SyncTest, BadRequest__10) {
	JSDL::Engine e;
	const char* test0 = "linkedin.com";
	for (int i = 0; i < 10; ++i) {
		Object3 ob0;
		e.deserialize(test0, ob0);
		EXPECT_STREQ(ob0.get().c_str(), "");
	}
}

TEST(AsyncTest, GoodRequest__SuitableObject__10) {
	JSDL::Engine e;
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
	EXPECT_STREQ(ob0.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob1.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob2.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob3.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob4.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob5.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob6.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob7.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob8.get().c_str(), "08-05-2021");
	EXPECT_STREQ(ob9.get().c_str(), "08-05-2021");
}

TEST(AsyncTest, GoodRequest__InappropriateObject__10) {
	JSDL::Engine e;
	Object3 ob0;
	const char* test0 = "ip.jsontest.com";

	e.asyncDes(test0, ob0, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test0" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob1;
	const char* test1 = "ip.jsontest.com";

	e.asyncDes(test1, ob1, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test1" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob2;
	const char* test2 = "ip.jsontest.com";

	e.asyncDes(test2, ob2, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test2" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob3;
	const char* test3 = "ip.jsontest.com";

	e.asyncDes(test3, ob3, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test3" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob4;
	const char* test4 = "ip.jsontest.com";

	e.asyncDes(test4, ob4, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test4" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob5;
	const char* test5 = "ip.jsontest.com";

	e.asyncDes(test5, ob5, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test5" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob6;
	const char* test6 = "ip.jsontest.com";

	e.asyncDes(test6, ob6, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test6" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob7;
	const char* test7 = "ip.jsontest.com";

	e.asyncDes(test7, ob7, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test7" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob8;
	const char* test8 = "ip.jsontest.com";

	e.asyncDes(test8, ob8, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test8" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob9;
	const char* test9 = "ip.jsontest.com";

	e.asyncDes(test9, ob9, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test9" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	e.asyncUserRst();
	EXPECT_STREQ(ob0.get().c_str(), "");
	EXPECT_STREQ(ob1.get().c_str(), "");
	EXPECT_STREQ(ob2.get().c_str(), "");
	EXPECT_STREQ(ob3.get().c_str(), "");
	EXPECT_STREQ(ob4.get().c_str(), "");
	EXPECT_STREQ(ob5.get().c_str(), "");
	EXPECT_STREQ(ob6.get().c_str(), "");
	EXPECT_STREQ(ob7.get().c_str(), "");
	EXPECT_STREQ(ob8.get().c_str(), "");
	EXPECT_STREQ(ob9.get().c_str(), "");
}

TEST(AsyncTest, BadRequest__10) {
	JSDL::Engine e;
	Object3 ob0;
	const char* test0 = "linkedin.com";

	e.asyncDes(test0, ob0, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test0" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob1;
	const char* test1 = "linkedin.com";

	e.asyncDes(test1, ob1, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test1" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob2;
	const char* test2 = "linkedin.com";

	e.asyncDes(test2, ob2, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test2" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob3;
	const char* test3 = "linkedin.com";

	e.asyncDes(test3, ob3, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test3" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob4;
	const char* test4 = "linkedin.com";

	e.asyncDes(test4, ob4, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test4" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob5;
	const char* test5 = "linkedin.com";

	e.asyncDes(test5, ob5, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test5" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob6;
	const char* test6 = "linkedin.com";

	e.asyncDes(test6, ob6, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test6" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob7;
	const char* test7 = "linkedin.com";

	e.asyncDes(test7, ob7, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test7" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob8;
	const char* test8 = "linkedin.com";

	e.asyncDes(test8, ob8, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test8" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	Object3 ob9;
	const char* test9 = "linkedin.com";

	e.asyncDes(test9, ob9, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::Success)
			std::cout << "test9" << std::endl;
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
	});

	e.asyncUserRst();
	EXPECT_STREQ(ob0.get().c_str(), "");
	EXPECT_STREQ(ob1.get().c_str(), "");
	EXPECT_STREQ(ob2.get().c_str(), "");
	EXPECT_STREQ(ob3.get().c_str(), "");
	EXPECT_STREQ(ob4.get().c_str(), "");
	EXPECT_STREQ(ob5.get().c_str(), "");
	EXPECT_STREQ(ob6.get().c_str(), "");
	EXPECT_STREQ(ob7.get().c_str(), "");
	EXPECT_STREQ(ob8.get().c_str(), "");
	EXPECT_STREQ(ob9.get().c_str(), "");
}