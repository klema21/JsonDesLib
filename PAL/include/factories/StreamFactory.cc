#include "StreamFactory.h"

std::shared_ptr<PAL::IStream> PAL::StreamFactory::makeStream(
	const char* uri, callbackFunct callback){
	
	return std::make_shared<HTTPStreamBuffer>(uri, callback);
}

using namespace PAL;
using namespace std;

function<shared_ptr<IStream>(const char*, callbackFunct)> StreamFactory::createStream = StreamFactory::makeStream;