#ifndef ISTREAM_H
#define ISTREAM_H

// IStream.h : Declaration of the IStream
//
// This is a part of the JSON Deserialization Library.
//
// Permission to use, copy, and modify this software 
// for educational purposes is hereby granted without fee.
//
// The author of library make no representations about the suitability 
// of this software for any purpose. It is provided "as is" without 
// express or implied warranty.

/*
	An interface that provide a concept for reading JSON and
	transport of characters to and from, and buffering of 
	these characters in an internal buffer.
*/

#include <cstddef>
#include <cstdint>

namespace PAL {
	class IStream {
	public:
		/**
		* Reading the whole buffer`s data.
		*
		* @return values JSON string data.
		*/
		virtual std::size_t read(uint8_t* dst, size_t size) = 0;
		/**
		* Flushing read data to the beginning of the buffer.
		*
		*/
		virtual void reset() = 0;
		/**
		* Return the size of buffer`s available data.
		*
		* @return values of JSON data size.
		*/
		virtual std::size_t available() const = 0;
		/**
		* Return the size of buffer`s data.
		*
		* @return values of JSON data size.
		*/
		virtual std::size_t total() const = 0;
		/**
		* Deleting a derived class object using a pointer to a base class.
		*/
		virtual ~IStream() {}
	};
}

#endif