#ifndef STREAMFACTORY_H
#define STREAMFACTORY_H

#include "../../PAL/include/AbstractFactory.h"
#include "../stream/streamBuffer/StreamBuffer.h"
#include "../stream/HTTPStreamBuffer/HTTPStreamBuffer.h"

namespace PAL {
	class StreamFactory : public PAL::AbstractFactory {
	public:
		static std::shared_ptr<PAL::IStream> makeStream(const char* uri);
	};
}

#endif
