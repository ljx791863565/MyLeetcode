#include "TcpServer.h"


struct Request
{
	char type;
	union {
		struct 
		{
			int fd;
			char ip[32];
			uint16_t port;
		} listen;
		struct 
		{
			int fd;
			char ip[32];
			uint16_t port;
		} connect;
		struct 
		{
			int fd;
		} start;
		struct 
		{	
			int fd;
		} close;
		struct 
		{
			int fd;
			int sz;
			void* data;
		} write;
		struct 
		{	
		} exit;
	} u;
};
TcpServer::TcpServer() :
	poller_(new Epoller()),
	indexEvent_(0)
{
	if ( ::pipe(reqfd_) < 0 )
		::abort();
	reqchannel_.reset(new Channel(reqfd_[0]));
	reqchannel_->type = Channel::kCommond;
	reqchannel_->enableRead();
	if (poller_->updateChannel(reqchannel_.get()) < 0) {
		::abort();
	}
}
int TcpServer::listen(std::string ip, uint16_t port) {
	int fd = Socket::createSocketNonBlocking();
	if (fd < 0)
		return -1;
	Request req;
	memset(&req, 0, sizeof(req));
	req.type = 'L';
	req.u.listen.fd = fd;
	strcpy(req.u.listen.ip, ip.c_str());
	req.u.listen.port = port;
	sendCommond(reqfd_[1], req);
	return fd;
}
int TcpServer::connect(std::string ip, uint16_t port) {
	int fd = Socket::createSocketNonBlocking();
	if (fd < 0)
		return -1;
	Request req;
	memset(&req, 0, sizeof(req));
	req.type = 'C';
	req.u.connect.fd = fd;
	strcpy(req.u.connect.ip, ip.c_str());
	req.u.connect.port = port;
	sendCommond(reqfd_[1], req);
	return fd;
}
void TcpServer::sendCommond(int fd, const Request& req) {
	while(1) {
		int n = ::write(fd, &req, sizeof(req));
		if (n < 0)
			continue;
		assert(n == sizeof(req));
		break;
	}
}
SocketState TcpServer::doCommond(Channel* channel, SockMessage* result) {
	Request req;
	memset(&req, 0, sizeof(req));
	while(1) {
		cout << "123" << endl;
		int n = read(reqfd_[0], &req, sizeof(req));
		cout << "n = " << n  << endl;
		if (n < 0) 
			continue;
		assert(n == sizeof(req));
		break;
	}
	cout << "req.type " << req.type << endl;
	switch(req.type) {
		case 'L' : doListen(req, result);
		case 'C' : doConnect(req, result);
		case 'W' : doWrite(channel, result);	
		case 'S' : doStart(req, result);
		case 'X' : doClose(req, result);
		case 'E' :  kExit;
		default:
			break;
	}
	return kInvalid;
}
void TcpServer:: write(int fd, const void* data, int sz) {
	Request req;
	memset(&req, 0, sizeof(req));
	req.type = 'W';
	req.u.write.fd = fd;
	req.u.write.sz = sz;
	req.u.write.data = const_cast<void*>(data);
	sendCommond(reqfd_[1], req);
}

void TcpServer::exit() {
	Request req;
	memset(&req, 0, sizeof(req));
	req.type = 'E';
	sendCommond(reqfd_[1], req);
}
void TcpServer::start(int fd) {
	Request req;
	memset(&req, 0, sizeof(req));
	req.type = 'S';
	req.u.start.fd = fd;
	sendCommond(reqfd_[1], req);
}
void TcpServer::close(int fd) {
	Request req;
	memset(&req, 0, sizeof(req));
	req.type = 'X';
	req.u.close.fd = fd;
	sendCommond(reqfd_[1], req);
}
SocketState TcpServer::poll(SockMessage* result) {
	if (indexEvent_ == static_cast<int>(activeChannels_.size())) {
		activeChannels_.clear();
		poller_->wait(1000, &activeChannels_);
		indexEvent_ = 0;
	}
	while (indexEvent_ < static_cast<int>(activeChannels_.size())) {
		auto channel = activeChannels_[indexEvent_];
		cout << "channel ->type " << channel->type << endl;
		switch(channel->type) {
			case  Channel::kCommond :
				return doCommond(channel, result);
			case  Channel::kListen :
				return doAccept(channel, result);
			case  Channel::kConnecting :
				return doConnect(channel, result);
			case  Channel::kConnectd :
				if (channel->hasWrite())
					doWrite(channel, result);
				if (channel->hasRead())
					doRead(channel, result);
				break;
			default:
				return kInvalid;
		}
	}
	return kInvalid;
}
SocketState TcpServer::doListen(const Request& req, SockMessage* result) {
	result->fd = req.u.listen.fd;
	result->ud = 0;
	result->data = nullptr;

	auto it1 = channels_.find(req.u.listen.fd);
	auto it2 = sockets_.find(req.u.listen.fd);
	if (it1 != channels_.end() || it2 != sockets_.end()) {
		return kError;
	}
	shared_ptr<Socket> socket(new Socket(req.u.listen.fd));
	if (socket->setReuseAddr(true) < 0)
		return kError;
	if (socket->setReusePort(true) < 0)
		return kError;
	if (socket->listen() < 0)
		return kError;
	shared_ptr<Channel> channel(new Channel(req.u.listen.fd));
	channel->type = Channel::kListen;
	channels_.insert({req.u.listen.fd, channel});
	sockets_.insert({req.u.listen.fd, socket});

	return kInvalid;
}
SocketState TcpServer::doConnect(Channel* channel, SockMessage* result) {
	result->fd = channel->fd();
	result->ud = 0;
	result->data = nullptr;
	channel->type = Channel::kConnectd;
	channel->disableWrite();
	channel->enableRead();
	poller_->updateChannel(channel);
	return kOpen;
}
SocketState TcpServer::doConnect(const Request& req, SockMessage* result) {
	result->fd = req.u.connect.fd;
	result->ud = 0;
	result->data = nullptr;

	auto it1 = channels_.find(req.u.listen.fd);
	auto it2 = sockets_.find(req.u.listen.fd);
	if (it1 != channels_.end() || it2 != sockets_.end()) {
		return kError;
	}
	shared_ptr<Socket> socket(new Socket(req.u.listen.fd));
	shared_ptr<Channel> channel(new Channel(req.u.listen.fd));

	socket->connect(InetAddress(req.u.connect.ip, req.u.connect.port));
	channel->type = Channel::kConnecting;
	channel->enableWrite();

	poller_->updateChannel(channel.get());

	channels_.insert({req.u.connect.fd, channel});
	sockets_.insert({req.u.connect.fd, socket});
	return kInvalid;
}
SocketState TcpServer::doAccept(Channel* channel, SockMessage* result) {
	result->fd = channel->fd();
	result->ud = 0;
	result->data  = nullptr;

	auto socket = sockets_[channel->fd()];

	InetAddress peerAddr(0);
	int fd = socket->accept(&peerAddr);
	if (fd < 0)
		return kError;

	shared_ptr<Socket> clientSocket(new Socket(fd));
	if (clientSocket->setKeepAlive(true) < 0)
		return kError;

	shared_ptr<Channel> clientChannel(new Channel(fd));
	clientChannel->type = Channel::kAccept;

	sockets_.insert({fd, clientSocket});
	channels_.insert({fd, clientChannel});

	strcpy(buffer_, peerAddr.toIpPort().c_str());
	result->ud = fd;
	result->data = buffer_;

	return kAccept;
}

SocketState TcpServer::doStart(const Request& req, SockMessage* result) {
	result->fd = req.u.start.fd;
	result->ud = 0;
	result->data = nullptr;

	auto it1 = channels_.find(req.u.start.fd);
	auto it2 = sockets_.find(req.u.start.fd);

	if (it1 == channels_.end() || it2 == sockets_.end()) {
		return kError;
	}

	auto channel = channels_[req.u.start.fd];
	if (channel->type != Channel::kListen && channel->type != Channel::kAccept)
		return kError;
	channel->enableRead();
	poller_->updateChannel(channel.get());

	channel->type = (channel->type == Channel::kPListen ? Channel::kListen : Channel::kConnectd );
	return kOpen;
}
SocketState TcpServer::doClose(const Request& req, SockMessage* result) {
	int fd = req.u.close.fd;
	auto it1 = channels_.find(fd);
	auto it2 = sockets_.find(fd);

	if (it1 == channels_.end() || it2 == sockets_.end()) {
		return kError;
	}
	auto channel = channels_[fd];
	auto socket = sockets_[fd];
	channel->disableAll();

	poller_->updateChannel(channel.get());
	
	channels_.erase(fd);
	sockets_.erase(fd);
	return kClose;
}

SocketState TcpServer::doWrite(Channel* channel, SockMessage* result) {
	int fd = channel->fd();
	auto socket = sockets_[fd];

	if (channel->isWriting()) {
		size_t n = ::write(channel->fd(), socket->outputBuffer().peek(), socket->outputBuffer().readableBytes());
		if (n > 0) {
			socket->outputBuffer().retrieve(n);
			if (socket->outputBuffer().readableBytes() == 0) {
				channel->disableWrite();
				if (channel->type == Channel::kDisConnecting)
					socket->shutdownWrite();
			}
		} else {
			switch(errno) {
				case EINTR:
				case EAGAIN:
					n = 0;
					break;
				default:
					channel->disableAll();
					poller_->updateChannel(channel);
					channels_.erase(fd);
					sockets_.erase(fd);
					return kClose;
			}
		}
	}
	return kInvalid;
}

SocketState TcpServer::doRead(Channel* channel, SockMessage* result) {
	result->fd = channel->fd();
	result->ud = 0;
	result->data = nullptr;

	int fd = channel->fd();
	int sz = 64;
	char* buffer = new char[sz];
	memset(buffer, 0, sz);

	int n = ::read(fd, buffer, sz);
	if (n < 0) {
		delete [] buffer;
		return kError;
	} else if (n == 0) {
		delete [] buffer;
		channel->disableAll();
		poller_->updateChannel(channel);
		channels_.erase(fd);
		sockets_.erase(fd);
		return kClose;
	}
	result->ud = n;
	result->data = buffer;
	return kData;
 }
