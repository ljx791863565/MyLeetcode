#include "Channel.h"

Channel::Channel(int fd) : 
	fd_(fd), 
	events_(kNoneEvent), 
	revents_(kNoneEvent),
	state(kNew), 
	type(kInvalid)
{
	
}