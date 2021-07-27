#include "ParserFactory.h"

std::shared_ptr<IParser> ParserFactory::makeParser() {
	return std::make_shared<Parser>();
}

std::function<std::shared_ptr<IParser>()> AbstractFactory::createParser = ParserFactory::makeParser;