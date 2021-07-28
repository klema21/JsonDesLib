#include "StreamFactory.h"

std::shared_ptr<PAL::IStream> PAL::StreamFactory::makeStream(const char* uri) {
	return std::make_shared<HTTPStreamBuffer>(uri);
}

std::function<std::shared_ptr<PAL::IStream>(const char*)> PAL::AbstractFactory::createStream = PAL::StreamFactory::makeStream;
