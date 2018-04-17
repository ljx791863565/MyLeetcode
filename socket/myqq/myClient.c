#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFSIZE 1024
int main(int argc, char *argv[])
{
	if (argc != 3){
		printf("number of algument error\n");
		return -1;
	}
	int clientFd;
	struct sockaddr_in clientAddr;
	memset(&clientAddr, 0, sizeof(clientAddr));

	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons((argv[2]));
	clientAddr.sin_addr.s_addr = inet_addr(argv[1]);

	if ((clientFd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		return -1;
	}

	if (connect(clientFd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0){
		perror("connect");
		return -1;
	}
	printf("connect to %d", argv[1]);

	char buf[BUFSIZE];
	while (1){
		memset(buf, 0, sizeof(buf));
		//给服务器发送消息
		int ret = read(0, buf, sizeof(buf));
		if (ret < 0){
			perror("read");
			close(clientFd);
			return -1;
		}
		ret = write(clientFd, buf, ret);
		if (ret < 0){
			perror("write");
			close(clientFd);
			return -1;
		}
		printf("client send msg : %s\n",buf);

		
	}
	close(clientFd);
	return 0;
}
