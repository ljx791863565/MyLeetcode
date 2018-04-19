#ifndef EPOLLER
#define EPOLLER 
#include "common.h"
#include <vector>
#include "Channel.h"

class Epoller
{
	using ChannelList = std::vector<Channel*>;
public:
	Epoller();
	~Epoller();
	void wait(int timeout, ChannelList* activeChannels);
	int updateChannel(Channel* channel);
private:
	int update(int operation, Channel* channel);
	int epfd_;
	std::vector<struct epoll_event> events_;
};
#endif	