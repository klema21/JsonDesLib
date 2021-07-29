#ifndef IPARSER_H
#define IPARSER_H

// IParser.h : Declaration of the IParser
//
// This is a part of the JSON Deserialization Library.
//
// Permission to use, copy, and modify this software 
// for educational purposes is hereby granted without fee.
//
// The author of library make no representations about the suitability 
// of this software for any purpose. It is provided "as is" without 
// express or implied warranty.

#include "../../../library/IEngine.h"
#include "IStream.h"
#include <memory>
/*
	Engine-related interface for inheriting new parsers.
*/
namespace PAL {
	class IParser {
	public:
		/**
		* Parses a JSON from a stream.
		*
		* @param values stream data that containing characters of string type.
		* @param values engine interface to publish events from handler to engine.
		*/
		virtual void parseStream(std::shared_ptr<PAL::IStream> is, JSDL::IEngine* e) = 0;
		/**
		* Deleting a derived class object using a pointer to a base class.
		*/
		virtual ~IParser() {};
	};
}

#endif