#include "ParserFactory.h"

std::shared_ptr<PAL::IParser> PAL::ParserFactory::makeParser() {
	return std::make_shared<Parser>();
}

using namespace PAL;
using namespace std;

function<shared_ptr<IParser>()> ParserFactory::createParser = ParserFactory::makeParser;