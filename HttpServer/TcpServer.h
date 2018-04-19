#ifndef TCP_SERVER_H
#define TCP_SERVER_H 
#include "common.h"
#include "Channel.h"
#include "Epoller.h"
#include "Socket.h"
#include "InetAddress.h"
#include <vector>
#include <map>
#include <memory>
#include <iostream>
using namespace std;

struct Request;
struct SockMessage {
	int fd;
	int ud;
	char* data;
};
enum SocketState
{
	kInvalid,
	kData,
	kClose,
	kOpen,
	kAccept,
	kError,
	kExit
};
class TcpServer
{
	
	using ChannelList = std::vector<Channel*>;
public:
	TcpServer();
	~TcpServer() {}
	int listen(std::string ip, uint16_t port);
	int connect(std::string ip, uint16_t port);

	void start(int fd);
	void close(int fd);
	void write(int fd, const void* data, int sz);
	void exit();
	void sendCommond(int fd, const Request& req);
	SocketState doCommond(Channel* channel, SockMessage* result);
	SocketState poll(SockMessage* result);

	SocketState doListen(const Request& req, SockMessage* result);
	SocketState doAccept(Channel* channels, SockMessage* result);
	SocketState  doConnect(Channel* channel, SockMessage* result);
	SocketState doConnect(const Request& req, SockMessage* result);
	SocketState doStart(const Request& req, SockMessage* result);
	SocketState doClose(const Request& req, SockMessage* result);
	SocketState doWrite(Channel* channel,  SockMessage* result);
	SocketState doRead(Channel* channel, SockMessage* result);

private:
	int reqfd_[2];
	int indexEvent_;
	unique_ptr<Channel> reqchannel_;
	unique_ptr<Epoller> poller_;
	ChannelList activeChannels_;

	std::map<int, shared_ptr<Channel> > channels_;
	std::map<int, shared_ptr<Socket> > sockets_;

	char buffer_[128];
};
#endif	