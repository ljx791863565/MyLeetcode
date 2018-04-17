#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 1024
#define MAXLISTEN 20

void thread(void *args)
{
	char buf[BUFSIZE];
	int ret;
	int fd = *(int*)args;
	while (1){
		memset(buf, 0, sizeof(buf));
		ret = read(fd, buf, sizeof(buf));
		if (ret < 0){
			perror("read");
			close(fd);
			return ;
		}
		printf("client send: %s\n", buf);
		memset(buf, 0, sizeof(buf));
		ret = read(0, buf, sizeof(buf));
		if (ret < 0){
			perror("read");
			return ;
		}
		ret = write(fd, buf, ret);
		if (ret < 0){
			perror("write");
			return ;
		}
		printf("server send: %s\n", buf);
	}
}
int main(int argc, char *argv[])
{
	if (argc != 2){
		printf("number of alguments error\n");
		return -1;
	}
	int clientFd, serverFd;
	struct sockaddr_in serverAddr, clientAddr;
	int cLen = sizeof(clientAddr);

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(argv[1]);
	serverAddr.sin_addr.s_addr = inet_addr(INADDR_ANY);

	if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		return -1;
	}
	if (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
		perror("bind");
		return -1;
	}
	if (listen(serverFd, MAXLISTEN) < 0){
		perror("listen");
		return -1;
	}
	while (1)
	{
		memset(&clientAddr, 0, sizeof(clientAddr));
		if ((clientFd = accept(serverFd, (struct sockaddr*)&clientAddr, &cLen)) < 0){
			perror("accept");
			return -1;
		}
		printf("connect foem %d\n", inet_ntoa(clientAddr.sin_addr));

		pthread_t pid;
		if (pthread_create(&pid, NULL, thread, &clientFd) < 0){
			perror("pthread_create");
			close(clientFd);
			return -1;
		}
		pthread_join(pid, NULL);
	}
	close(serverFd);
	return -1;
}

