#ifndef ENGINE_H
#define ENGINE_H

// Engine.h : Declaration of the Engine
//
// This is a public part of the JSON Deserialization Library.
//
// Permission to use, copy, and modify this software 
// for educational purposes is hereby granted without fee.
//
// The author of library make no representations about the suitability 
// of this software for any purpose. It is provided "as is" without 
// express or implied warranty.

#include "ISerializable.h"
#include "../library/Status.h"
#include <functional>

typedef std::function<void(JSDL::Status)> callbackFunct;

namespace JSDL {
	class Engine {
	public:
		/**
		* Deserialize user`s object with transmitted data.
		*
		* @param values JSON string data.
		* @param values user`s object that would be filled with JSON string data
		*/
		void deserialize(const char* uri, ISerializable& d);

		void asyncDeserialize(const char* uri, ISerializable& d, callbackFunct callback);

		void asyncDeserializeRun();
	};
}

#endif