#ifndef STREAMFACTORY_H
#define STREAMFACTORY_H

#include "../../stream/streamBuffer/StreamBuffer.h"
#include "../../stream/HTTPStreamBuffer/HTTPStreamBuffer.h"
#include "../interfaces/IStream.h"
#include <functional>
#include <memory>


namespace PAL {
	class StreamFactory {
	public:
		static std::shared_ptr<PAL::IStream> makeStream(const char* uri);
		static std::function<std::shared_ptr<PAL::IStream>(const char*)> createStream;
	};
}

#endif
