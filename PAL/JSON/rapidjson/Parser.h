#ifndef PARSER_H
#define PARSER_H

#include "../../include/IParser.h"

#include "../../../3rdparty/rapidjson/reader.h"
#include "../../../3rdparty/rapidjson/writer.h"
#include "../../../3rdparty/rapidjson/document.h"

namespace PAL {
	class Parser : public PAL::IParser {
		struct Handler
			: public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, Handler> {
		private:
			JSDL::IEngine* _e;
			enum State {
				kExpectedKey,
				kExpectedValue,
				kArrayStarted,
				kObjectEnd
			} state_;
			std::string name_;
			std::string arrayName_;
			int counter = 0;
			bool isArray = false;
		public:
			Handler(JSDL::IEngine* e) : _e(e) {
				state_ = kExpectedKey;
			}
			bool StartObject() {
				if (counter == 0) {
					++counter;
					return true;
				}
				else if (isArray) {
					_e->newObject(arrayName_);
				}
				else {
					_e->newObject(name_);
				}
				state_ = kExpectedKey;
				return true;
			}
			bool String(const char* str, rapidjson::SizeType length, bool) {
				switch (state_) {
				case kExpectedKey:
					name_ = str;
					state_ = kExpectedValue;
					return true;
				case kExpectedValue:
					_e->newValue(name_, static_cast<std::string>(str));
					state_ = kExpectedKey;
					return true;
				};
				return true;
			}

			bool Int(int i) {
				switch (state_) {
				case kExpectedValue:
					_e->newValue(name_, i);
					state_ = kExpectedKey;
					return true;
				case kArrayStarted:
					_e->newValue(name_, i);
					return true;
				}
				return true;
			}

			bool Uint(unsigned u) {
				switch (state_) {
				case kExpectedValue:
					_e->newValue(name_, static_cast<int>(u));
					state_ = kExpectedKey;
					return true;
				case kArrayStarted:
					_e->newValue(name_, static_cast<int>(u));
					return true;
				}
				return true;
			}
			bool Double(double d) {
				switch (state_) {
				case kExpectedValue:
					_e->newValue(name_, d);
					state_ = kExpectedKey;
					return true;
				}
				return true;
			}
			bool Bool(bool b) {
				switch (state_) {
				case kExpectedValue:
					_e->newValue(name_, b);
					state_ = kExpectedKey;
					return true;
				}
				return true;
			}
			bool StartArray() {
				isArray = true;
				arrayName_ = name_;
				state_ = kArrayStarted;
				return true;
			}

			bool EndArray(rapidjson::SizeType) {
				isArray = false;
				state_ = kExpectedKey;
				return true;
			}
			bool EndObject(rapidjson::SizeType) {
				_e->endObject();
				state_ = kExpectedKey;
				return true;
			}
			bool Default() {
				return false;
			}
		};
	public:
		void parseStream(std::shared_ptr<PAL::IStream> is, JSDL::IEngine* e);
	};
}
#endif