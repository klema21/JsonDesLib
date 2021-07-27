#include "Parser.h"

void Parser::parseStream(std::shared_ptr<JDLS::IStream> is, IEngine* e) {
	Handler h = Handler(e);
	rapidjson::Reader read;
	auto jsonLen = is->available();
	auto json = new uint8_t[jsonLen];
	auto status = is->read(json, jsonLen);
	const char* tmp = reinterpret_cast<char*>(json);
	rapidjson::StringStream ss(tmp);
	read.Parse(ss, h);
	delete json;
}