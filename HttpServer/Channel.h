#ifndef CHANNEL_H
#define CHANNEL_H 
#include "noncopyable.h"

class Channel : noncopyable
{
public:
	enum State
	{
		kNew,
		kAdd,
		kDelete
	};
	enum Type
	{
		kInvalid,
		kCommond,
		kListen,
		kConnectd,
		kConnecting,
		kDisConnecting,
		kAccept,
		kPListen
	};
public:
	Channel(int fd) ;
	~Channel(){}

	int fd() { return fd_; }
	int event() { return events_; }

	void enableRead() { events_ |= kReadEvent; }
	void enableWrite() { events_ |= kWriteEvent; }
	//others
	void disableAll() {events_ &= 0; }
	void disableRead() { events_ &= ~kReadEvent; }
	void disableWrite() { events_ &= ~kWriteEvent; }
	//others
	bool isNoneEvent() { return events_ == kNoneEvent; }
	bool isReadEvent() { return events_ & kReadEvent; }
	//others
	void setEvent(int e) {events_ = e; }

	bool isWriting() const {return events_ & kWriteEvent; }
	bool isReading() const {return events_ & kReadEvent; }

	bool hasWrite() const { return revents_ & kWriteEvent; }
	bool hasRead() const {return revents_ & kReadEvent;}
	State state;
	Type type;

	static const int kNoneEvent = 0b0001;
	static const int kReadEvent = 0b0010;
	static const int kWriteEvent = 0b0100;
	static const int kErrorEvent = 0b1000;
private:
	int fd_;
	int events_;
	int revents_;
};
#endif	