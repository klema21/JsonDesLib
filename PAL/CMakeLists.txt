if(WIN32)
	add_library(PAL include/ParserFactory.cc 
		include/StreamFactory.cc 
		JSON/rapidjson/Parser.cc
		stream/streamBuffer/StreamBuffer.cc
		stream/HTTPStreamBuffer/HTTPWINClientFactory.cc
		stream/HTTPStreamBuffer/HTTPStreamBuffer.cc)
endif(WIN32)

if(UNIX)
	add_library(PAL JSON/rapidjson/Parser.cc
		stream/HTTPStreamBuffer/HTTPClientFactory.cc
		stream/HTTPStreamBuffer/HTTPStreamBuffer.cc
		include/ParserFactory.cc
		include/StreamFactory.cc
		stream/streamBuffer/StreamBuffer.cc)
endif(UNIX)
