#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include "../../PAL/include/AbstractFactory.h"
#include "../JSON/rapidjson/Parser.h"

class ParserFactory : public AbstractFactory{
public:
	static std::shared_ptr<IParser> makeParser();
	static std::function<std::shared_ptr<IParser>()> createParser;
};

#endif