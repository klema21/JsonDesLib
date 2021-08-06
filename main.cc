#include "test/objects/Object3.h"
#include "Engine.h"

int main() {
	JSDL::Engine e;
	Object3 ob;
	const char* test = "datejsontecom";
	e.asyncDes(test, ob, [](JSDL::Status result) {
		if (result.m_status == JSDL::Status::send_status::ConnectionError)
			std::cout << result.what() << std::endl;
		if (result.m_http_status == JSDL::Status::http_status::ERROR) {
			std::cout << result.statusCode() << std::endl;
		}
	});
	e.asyncUserRst();

	Object3 ob1;
	e.deserialize(test, ob1);

	return 0;
}
