#ifndef STREAMBUFFER_H
#define STREAMBUFFER_H

#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>

#include "../../../PAL/include/IStream.h"

/*
	The main task of the stream buffer is transport of characters to and from this external device, and buffering of these characters in an internal buffer.
*/

class StreamBuffer : public JDLS::IStream {
public:
	StreamBuffer();
	StreamBuffer(const char* src);
	StreamBuffer(const char* src, std::size_t size);
	StreamBuffer(const StreamBuffer&);
	~StreamBuffer();

	std::size_t read(uint8_t* dst, size_t size);
	void reset();
	std::size_t available() const;
	std::size_t total() const;

	void initializeZeroBuff();
	void initializeNewBuff(std::size_t size, const char* src);

	StreamBuffer& operator=(StreamBuffer&) = delete;
	StreamBuffer(StreamBuffer&&) = delete;
	StreamBuffer& operator=(StreamBuffer&&) = delete;
private:
	std::size_t m_size{ 0 };
	std::size_t m_curr{ 0 };
	char* m_buff{ nullptr };
};

#endif
