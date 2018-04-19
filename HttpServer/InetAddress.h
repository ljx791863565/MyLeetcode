#ifndef INET_ADDRESS_H
#define INET_ADDRESS_H 
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <arpa/inet.h>
// #include <fcntl.h>
#include "InetAddress.h"

class InetAddress
{
public:
	explicit InetAddress(uint16_t port);
	InetAddress(const struct sockaddr_in& addr);
	InetAddress(std::string ip, uint16_t port);
	InetAddress(const InetAddress& addr);
	~InetAddress() {}
	std::string toIpPort();
	void set(struct sockaddr_in& addr) { address_ = addr; }
	const struct sockaddr_in& get() const {return address_;}
private:
	struct sockaddr_in address_;
};
#endif	