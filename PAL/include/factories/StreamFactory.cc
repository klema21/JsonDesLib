#include "StreamFactory.h"

std::shared_ptr<PAL::IStream> PAL::StreamFactory::makeStream(
	const char* uri, std::function<void(JSDL::Status)> f) {
	
	return std::make_shared<HTTPStreamBuffer>(uri);
}

std::function<
	std::shared_ptr<
		PAL::IStream>(const char*, std::function<void(JSDL::Status)>)> 
			PAL::StreamFactory::createStream = PAL::StreamFactory::makeStream;