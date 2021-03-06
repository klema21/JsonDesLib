#include "StreamBuffer.h"

PAL::StreamBuffer::StreamBuffer() {
	initializeZeroBuff();
}

PAL::StreamBuffer::StreamBuffer(const char* src) {
	if (src == nullptr) {
		initializeZeroBuff();
	} else {
		initializeNewBuff(strlen(src) + 1, src);
	}
}

PAL::StreamBuffer::StreamBuffer(const char* src, std::size_t size) {
	if (src == nullptr) {
		initializeZeroBuff();
	} else {
		initializeNewBuff(size, src);
	}
}

PAL::StreamBuffer::StreamBuffer(const StreamBuffer& source) {
	std::size_t size = strlen(source.m_buff + 1);
	delete m_buff; 
	m_buff = nullptr;
	initializeNewBuff(size, source.m_buff);
}

std::size_t PAL::StreamBuffer::read(uint8_t* dst, size_t size) {
	if (m_curr < m_size) {
		auto length = (m_curr + size) < m_size ? m_curr + size : m_size;
		std::copy(m_buff + m_curr, m_buff + length, dst + m_curr);
		m_curr = length;
		return length;
	}
	return 0;
}

void PAL::StreamBuffer::reset() {
	m_curr = 0;
}

void PAL::StreamBuffer::initializeZeroBuff() {
	delete m_buff;
	m_buff = new char[1];
	m_buff[0] = '\0';
	m_size = 0;
}

void PAL::StreamBuffer::initializeNewBuff(std::size_t size, const char* src) {
	m_size = size;
	m_buff = new char[m_size];
	std::copy(src, src+m_size, m_buff);
}

std::size_t PAL::StreamBuffer::available() const {
	return m_size - m_curr;
}

std::size_t PAL::StreamBuffer::total() const {
	return m_size;
}

PAL::StreamBuffer::~StreamBuffer() {
	delete m_buff;
}