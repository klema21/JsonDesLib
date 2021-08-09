#include "Parser.h"

JSDL::Status PAL::Parser::parseStream(std::shared_ptr<PAL::IStream> is, JSDL::IEngine* e) {
	Handler h = Handler(e);
	rapidjson::Reader read;
	auto jsonLen = is->available();
	auto json = new uint8_t[jsonLen];
	auto status = is->read(json, jsonLen);
	const char* tmp = reinterpret_cast<char*>(json);
	rapidjson::StringStream ss(tmp);
	read.Parse(ss, h);
	delete[] json;
	
	JSDL::Status statuz;
	return statuz;

	//auto jsonLen = is->getData([&](std::size_t size) {
	/*auto jsonLen = is->_available([&](std::size_t size) {
		auto json = new uint8_t[size];
		auto status = is->read(json, size);
		const char* tmp = reinterpret_cast<char*>(json);
		rapidjson::StringStream ss(tmp);
		rapidjson::Reader read;
		read.Parse(ss, h);
		delete[] json;
	});*/

	//auto jsonLen = is->getData([&](std::size_t size) {
	/*auto jsonLen = is->_available([&](std::size_t size) {
		auto json = new uint8_t[size];
		auto status = is->read(json, size);
		const char* tmp = reinterpret_cast<char*>(json);
		rapidjson::StringStream ss(tmp);
		rapidjson::Reader read;
		read.Parse(ss, h);
		delete[] json;
	});*/

	// Conditional variable
	
}
