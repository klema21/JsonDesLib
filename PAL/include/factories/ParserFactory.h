#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include "../../JSON/rapidjson/Parser.h"
#include "../interfaces/IParser.h"
#include <functional>
#include <memory>

namespace PAL {
	class ParserFactory {
	public:
		static std::shared_ptr<PAL::IParser> makeParser();
		static std::function<std::shared_ptr<IParser>()> createParser;
	};
}

#endif
