#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <sys/wait.h>
#include <netinet/in.h>//定义结构体sockaddr_in
#include <sys/types.h>//数据类型定义
#include <sys/socket.h>//提供socket函数及数据结构
#include <arpa/inet.h>//提供IP地址转换函数


#define BUFSIZE 1024
#define PORT 8088
#define MAXLISTEN 10
int main(int argc, char *argv[])
{
//	if (argc != 2){
//		printf("number of argument error\n");
//		return -1;
//	}
	struct sockaddr_in serverAddr;
	int sockFd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockFd < 0){
		perror("socket");
		return -1;
	}
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
		perror("bind");
		return -1;
	}
	if (listen(sockFd, MAXLISTEN) < 0){
		perror("listen");
		return -1;
	}
	int reuse = 1;
	if (setsockopt(sockFd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0){
		perror("setsockapt");
		return -1;
	}
		
	char buf[BUFSIZE];
	while (1){
		memset(buf, 0, sizeof(buf));
		int clientFd;
		struct sockaddr_in clientAddr;
		socklen_t cLen = sizeof(clientAddr);
		clientFd = accept(sockFd, (struct sockaddr*)&clientAddr, &cLen);
		if (clientFd < 0){
			perror("accept");
			return -1;
		}
		int ret = read(clientFd, buf, sizeof(buf));
		printf ("got		connect		from	%s\n",inet_ntoa(clientAddr.sin_addr));
		printf("recv msg from client : %s\n", buf);
		close(clientFd);

	}
//	int ret = recv(newFd, buf, sizeof(buf), 0);
//	if (ret < 0){
//		perror("recv");
//		return -1;
//	}

//	printf("server recv msg from client: %s\n", buf);
	close(sockFd);
	return 0;
}
