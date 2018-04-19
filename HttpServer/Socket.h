#ifndef SOCKET_H
#define SOCKET_H 
#include "noncopyable.h"
#include "InetAddress.h"
#include "Buffer.h"
#include "common.h"
class InetAddress;

class Socket : noncopyable
{
public:
	explicit Socket(int fd);
	~Socket();

	int fd() {return fd_;}
	
	int bind(const InetAddress& addr);
	int listen();

	int accept(InetAddress* addr);
	int connect(const InetAddress& addr);

	static void setNonBlocking(int fd);
	static int createSocketNonBlocking();
	int shutdownWrite();

	int setReuseAddr(bool on);
	int setReusePort(bool on);
	int setKeepAlive(bool on);
	Buffer outputBuffer() { return outputBuffer_; }
	Buffer inputBuffer() { return inputBuffer_; }
private:
	int fd_;
	Buffer inputBuffer_;
	Buffer outputBuffer_;

};
#endif	