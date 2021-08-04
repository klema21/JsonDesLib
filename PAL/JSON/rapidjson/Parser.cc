#include "Parser.h"

void PAL::Parser::parseStream(std::shared_ptr<PAL::IStream> is, JSDL::IEngine* e) {
	std::lock_guard<std::mutex> lk(mtx);
	Handler h = Handler(e);
	rapidjson::Reader read;
	auto jsonLen = is->available();
	auto json = new uint8_t[jsonLen];
	auto status = is->read(json, jsonLen);
	const char* tmp = reinterpret_cast<char*>(json);
	rapidjson::StringStream ss(tmp);
	read.Parse(ss, h);
	delete[] json;
}
