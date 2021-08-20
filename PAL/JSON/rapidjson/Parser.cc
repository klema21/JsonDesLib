#include "Parser.h"

JSDL::Status PAL::Parser::parseStream(std::shared_ptr<PAL::IStream> is, JSDL::IEngine* e) {
	JSDL::Status parser_status;
	bool complete = true;
	
	Handler h = Handler(e);
	rapidjson::Reader read;
	auto jsonLen = is->available();
	if (jsonLen == 0)
		complete = false;
	auto json = new uint8_t[jsonLen];
	auto status = is->read(json, jsonLen);
	const char* tmp = reinterpret_cast<char*>(json);
	rapidjson::StringStream ss(tmp);
	read.Parse(ss, h);
	delete[] json;
	
	if (complete)
		parser_status.m_object_status = JSDL::Status::object_status::Complete;
	else
		parser_status.m_object_status = JSDL::Status::object_status::Error;

	return parser_status;	
}
