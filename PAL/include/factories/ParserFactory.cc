#include "ParserFactory.h"

std::shared_ptr<PAL::IParser> PAL::ParserFactory::makeParser() {
	return std::make_shared<Parser>();
}

std::function<std::shared_ptr<PAL::IParser>()> PAL::ParserFactory::createParser = PAL::ParserFactory::makeParser;