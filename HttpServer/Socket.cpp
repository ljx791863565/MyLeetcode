#include "Socket.h"

Socket::Socket(int fd) : fd_(fd){	
}

Socket::~Socket() {
	if (fd_ > 0) 
		close(fd_);
}

int Socket::bind(const InetAddress& addr)
{
	auto& address = addr.get();
	return ::bind(fd_, (struct sockaddr*)&address, sizeof(address));
}
int Socket::listen() {
	return ::listen(fd_, 5);
}

int Socket::accept(InetAddress* addr) 
{	
	struct sockaddr_in a;
	socklen_t len = sizeof(a);
	memset(&a, 0, sizeof(a));

	int confd = ::accept(fd_, (struct sockaddr*)&a, &len);
	if (confd >= 0) {
		setNonBlocking(confd);
		addr->set(a);
	}
	return confd;
}

int Socket::connect(const InetAddress& addr)
{
	auto& a = addr.get();
	return ::connect(fd_, (struct sockaddr*)&a, sizeof(a));
}
int Socket::shutdownWrite() {
	return ::shutdown(fd_, SHUT_WR);
}
void Socket::setNonBlocking(int fd)
{
	int flag = ::fcntl(fd, F_GETFL, 0);
	flag |= O_NONBLOCK;
	::fcntl(fd, F_SETFL, flag);
}
int Socket::createSocketNonBlocking() {
	int fd = ::socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return -1;
	setNonBlocking(fd);
	return fd;
}

int Socket::setReuseAddr(bool on) {
	int flag = on ? 1 : 0;
	return ::setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &flag, static_cast<socklen_t>(sizeof(flag)));
}
int Socket::setReusePort(bool on) {
	int flag = on ? 1 : 0;
	return ::setsockopt(fd_, SOL_SOCKET, SO_REUSEPORT, &flag, static_cast<socklen_t>(sizeof(flag)));
}
int Socket::setKeepAlive(bool on) {
	int flag = on ? 1 : 0;
	return ::setsockopt(fd_, SOL_SOCKET, SO_KEEPALIVE, &flag, static_cast<socklen_t>(sizeof(flag)));
}