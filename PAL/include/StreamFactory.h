#ifndef STREAMFACTORY_H
#define STREAMFACTORY_H

#include "../../PAL/include/AbstractFactory.h"
#include "../stream/streamBuffer/StreamBuffer.h"
#include "../stream/HTTPStreamBuffer/HTTPStreamBuffer.h"

class StreamFactory : public AbstractFactory {
public:
	static std::shared_ptr<JDLS::IStream> makeStream(const char* uri);
};

#endif
