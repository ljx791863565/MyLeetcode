#ifndef BUFFER_H
#define BUFFER_H 
#include <string>
#include <string.h>
#include <vector>
#include <assert.h>
/*
----------------------------------------------------------
	8|
----------------------------------------------------------
0	    readIndex_	writeIndex_	size
*/						
class Buffer
{
	static const size_t kCheapPrepend = 8;
	static const size_t kInitialSize = 1024;
public:
	Buffer(int initialSize = kInitialSize) 
		: buffer_(initialSize+8),
		readIndex_(kCheapPrepend),
		writeIndex_(kCheapPrepend) 
	{		
	}
	// ~Buffer() {}
	// append
	// toString
	void retrieve(size_t len) {
		assert(len <= readableBytes());
		if (len < readableBytes()) {
			readIndex_ += len;
		} else {
			retrieveAll();
		} 
	}
	void retrieveAll() {
		readIndex_ = kCheapPrepend;
		writeIndex_ = kCheapPrepend;
	}
	char* begin() {
		return &*buffer_.begin();
	}
	const char* begin() const {
		return &*buffer_.begin();
	}
	//获得下标readIndex_对应的字符的位置
	const char* peek() const {
		return begin() + readIndex_;
	}
	int16_t peekInt16() {
		assert(readableBytes() >= sizeof(int16_t));
		int16_t result = 0;
		memcpy(&result, peek(), sizeof(result));
		return result;
	}
	int16_t readInt16() {
		int16_t result = 0;
		result = peekInt16();
		retrieve(sizeof(result));
		return result;
	}
	//获得可写入的位置
	char* beginWrite() {
		return begin() + writeIndex_;
	}
	
	size_t readableBytes() const {
		return writeIndex_ - readIndex_ ;
	}  
	size_t writeableBytes() const {
		return buffer_.size() - writeIndex_;
	}
	size_t prependableBytes() const {
		return readIndex_;
	}
private:
	std::vector<char> buffer_;
	size_t readIndex_;
	size_t writeIndex_;
};		
#endif
