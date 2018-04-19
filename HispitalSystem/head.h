#ifndef __HEAD__H__
#define __HEAD__H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <sys/epoll.h>
#include <mysql/mysql.h>

#include "threadpool.h"
#define BUFSIZE 1024  //缓存区大小
#define MAXLISTEN 100 //监听的最大描述符数量
#define MAXEPOLL 20
#define MAX_OF_WAIT_TIME 500 //监听最大阻塞时间  超过500s将不再阻塞等待
typedef struct msghead
{
	int len;	//消息头长度
	int msgtype;//消息类型
	int result;	//返回的消息类型
}MSGHEAD_T;

typedef struct msg
{
	int fd;
	char buf[BUFSIZE];
}MSG_T;
#endif //__HEAD__H__
