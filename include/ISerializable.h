#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

// ISerializable.h : Declaration of the ISerializable
//
// This is a public part of the JSON Deserialization Library.
//
// Permission to use, copy, and modify this software 
// for educational purposes is hereby granted without fee.
//
// The author of library make no representations about the suitability 
// of this software for any purpose. It is provided "as is" without 
// express or implied warranty.

#include <iostream>
#include <string>
/*
	An open interface for inheriting new custom objects 
	that should work with the JSON Deserialization Library.
*/

namespace JSDL {
	class ISerializable {
	public:
		/**
		* Setting a string value in an object field.
		*
		* @param values string data of JSON name.
		* @param values string data of JSON value.
		*/
		virtual void setValue(const std::string& name, std::string value) = 0;
		/**
		* Setting a bool value in an object field.
		*
		* @param values string data of JSON name.
		* @param values bool data of JSON value.
		*/
		virtual void setValue(const std::string& name, bool value) = 0;
		/**
		* Setting an int value in an object field.
		*
		* @param values string data of JSON name.
		* @param values integer data of JSON value.
		*/
		virtual void setValue(const std::string& name, int value) = 0;
		/**
		* Setting a double value in an object field.
		*
		* @param values JSON name string data.
		* @param values double data type of JSON value.
		*/
		virtual void setValue(const std::string& name, double value) = 0;
		/**
		* Return a requesting object by name.
		*
		* @param values string data of object name.
		* @return reference of an object.
		*/
		virtual ISerializable& getObject(const std::string&) = 0;
		/**
		* Deleting a derived class object using a pointer to a base class.
		*/
		virtual ~ISerializable() {}
	};
}

#endif