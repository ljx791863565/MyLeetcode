#include "InetAddress.h"
InetAddress::InetAddress(const struct sockaddr_in& addr) : 
	address_(addr) 
{
}
InetAddress::InetAddress(uint16_t port) {
	memset(&address_, 0, sizeof(address_));
	address_.sin_family = AF_INET;
	address_.sin_addr.s_addr = INADDR_ANY;
	address_.sin_port = htons(port);
}
InetAddress::InetAddress(std::string ip, uint16_t port) {
	memset(&address_, 0, sizeof(address_));
	address_.sin_family = AF_INET;
	address_.sin_addr.s_addr = inet_addr(ip.c_str());
	address_.sin_port = htons(port);
}
InetAddress::InetAddress(const InetAddress& addr)  {
	address_ = addr.address_;
}
std::string InetAddress::toIpPort() {
	char buf[32] = {};
	char host[INET_ADDRSTRLEN] = {};
	uint16_t port = 0;
	inet_ntop(AF_INET, &address_.sin_addr, host, sizeof(host));
	port = ntohs(address_.sin_port);
	snprintf(buf, sizeof(buf), "%s : %d", host, port);
	return std::string(buf);
}