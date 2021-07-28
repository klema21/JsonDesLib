#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include "../../PAL/include/AbstractFactory.h"
#include "../JSON/rapidjson/Parser.h"

namespace PAL {
	class ParserFactory : public PAL::AbstractFactory {
	public:
		static std::shared_ptr<PAL::IParser> makeParser();
	};
}

#endif
