#include "StreamFactory.h"

std::shared_ptr<JDLS::IStream> StreamFactory::makeStream(const char* uri) {
	return std::make_shared<HTTPStreamBuffer>(uri);
	//return std::make_shared<StreamBuffer>(uri);
}

std::function<std::shared_ptr<JDLS::IStream>(const char*)> AbstractFactory::createStream = StreamFactory::makeStream;