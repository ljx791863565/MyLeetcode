#include "Epoller.h"

Epoller::Epoller() :
	epfd_(::epoll_create(1024)),
	events_(16)
{
	if (epfd_ < 0)
		::abort();
}
Epoller::~Epoller() {
	::close(epfd_);
}

void Epoller::wait(int timeout, ChannelList* activeChannels) {
	int numEvents = epoll_wait(epfd_, &*events_.begin(), static_cast<int>(events_.size()), timeout);
	for (int i=0; i<numEvents; i++) {
		Channel* channel =  (Channel*)events_[i].data.ptr;
		int ev = 0;
		if (events_[i].events & EPOLLERR)
			ev |= Channel::kErrorEvent;
		if (events_[i].events & (EPOLLIN | EPOLLPRI | EPOLLRDHUP ))
			ev |= Channel::kReadEvent;
		if (events_[i].events & EPOLLOUT)
			ev |= Channel::kWriteEvent;
		channel->setEvent(ev);
		activeChannels->push_back(channel);
	}
	if (static_cast<size_t>(numEvents) == events_.size()) 
		events_.resize(events_.size()*2);
}

int Epoller::updateChannel(Channel* channel) {
	if (channel->state == Channel::kNew || channel->state == Channel::kDelete) {
		channel->state = Channel::kAdd;
		return update(EPOLL_CTL_ADD, channel);
	} else if (channel->state == Channel::kAdd && channel->isNoneEvent()) {
		channel->state = Channel::kDelete;
		return update(EPOLL_CTL_DEL, channel);
	} else if (channel->state == Channel::kAdd) {
		return update(EPOLL_CTL_MOD, channel);
	} else 
		return -1;
}
int Epoller::update(int operation, Channel* channel) {
	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));
	if (channel->event() & Channel::kReadEvent)
		ev.events |= EPOLLIN | EPOLLPRI;
	if (channel->event() & Channel::kWriteEvent)
		ev.events |= EPOLLOUT;

	ev.data.ptr = channel;
	return epoll_ctl(epfd_, operation, channel->fd(), &ev);
}