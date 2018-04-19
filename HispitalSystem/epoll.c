#include "head.h"
void *myworker(void *arg)
{
	char buf[BUFSIZE];
	memset(buf, 0, sizeof(buf));
	MSG_T *pm = (MSG_T*)arg;
	MSGHEAD_T msghead;

	memcpy(&msghead, pm->buf, sizeof(buf));
	msghead.len = ntohl(msghead.len);
	msghead.msgtype = ntohl(msghead.msgtype);

	switch (msghead.msgtype)
	{
		case 1:
			myRegister(pm->fd, pm->buf);
			break;
		case 3:
			myLogin(pm->fd, pm->buf);
			break;
		

	}

}

int main(int argc, char *argv[]) //./server 8090
{
	if (argc != 2){
		printf("para error\n");
		return -1;
	}

	int epfd;//epoll文件描述符
	epfd = epoll_create(MAXLISTEN);
	
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <0){
		perror("socket");
		return -1;
	}

	struct sockaddr_in serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[1]));
	serverAddr.sin_addr.s_addr = inet_addr(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
		perror("bind");
		return -1;
	}

	if (listen(sockfd, MAXLISTEN) < 0){
		perror("listen");
		return -1;
	}

	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = sockfd;
	//把sockfd添加到epoll监听队列
	epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);

	//保存通知事件的数组
	struct epoll_event events[MAXEPOLL];
	//保存通知事件的个数
	int count = 0;

	char buf[BUFSIZE];
	int clientFd, readFd;
	struct sockaddr_in clientAddr;
	int cliLen = sizeof(clientAddr);
	memset(&clientAddr, 0, cliLen);
	
	MSGHEAD_T msghead;

	//线程池的创建和初始化,一般cpu有几个线程我们就创建几个线程的线程池
	pool_init(6);

	MSG_T *pmsg;
	
	while (1){
		count = epoll_wait(epfd, events, MAXEPOLL, MAX_OF_WAIT_TIME);
		//遍历所有的通知事件
		for (int i=0; i < count; ++i){
			//客户端第一次链接
			if (events[i].data.fd == sockfd){
				clientFd = accept(sockfd, (struct sockaddr*)&clientAddr, &cliLen);
				if (clientFd < 0){
					perror("accept");
					continue;
				}

				printf("A new client connectting ok\n");
				
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = clientFd;
				epoll_ctl(epfd, EPOLL_CTL_ADD, clientFd, &ev);
			}else if (events[i].events & EPOLLET){ //管道有数据可以读取
				readFd = events[i].data.fd;
				memset(buf, 0, sizeof(buf));

				int ret = read(readFd, buf, sizeof(buf));
				if (ret <= 0){
					continue;
				}
				pmsg = (MSG_T *)malloc(sizeof(MSG_T));
				if (pmsg == NULL){
					perror("malloc");
					return -1;
				}

				memset(pmsg, 0, sizeof(MSG_T));
				pmsg->fd = readFd;
				memcpy(pmsg->buf , buf, ret);

				pool_add_worker(myworker, pmsg);

			}
		}

		return 0;
	}


























}
