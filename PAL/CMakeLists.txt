if(WIN32)
	add_library(PAL include/factories/ParserFactory.cc  
		JSON/rapidjson/Parser.cc
		stream/streamBuffer/StreamBuffer.cc
		HTTP/HTTPClient/HTTPWINClientFactory.cc
		stream/HTTPStreamBuffer/HTTPStreamBuffer.cc
		include/factories/StreamFactory.cc)
endif(WIN32)

if(UNIX)
	add_library(PAL JSON/rapidjson/Parser.cc
		HTTP/HTTPClient/HTTPClientFactory.cc
		stream/HTTPStreamBuffer/HTTPStreamBuffer.cc
		include/factories/ParserFactory.cc
		include/factories/StreamFactory.cc
		stream/streamBuffer/StreamBuffer.cc)
endif(UNIX)