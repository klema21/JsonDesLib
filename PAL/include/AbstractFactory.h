#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "../PAL/include/IParser.h"
#include "../PAL/include/IStream.h"
#include <functional>
#include <memory>

class AbstractFactory {
public:
//	virtual std::shared_ptr<IParser> makeParser() = 0;
//	virtual std::shared_ptr<JDLS::IStream> makeStream(const char* uri) = 0;
	static  std::function<std::shared_ptr<IParser>()> createParser;
	static  std::function<std::shared_ptr<JDLS::IStream>(const char*)> createStream;
	virtual ~AbstractFactory() {};
};

#endif
