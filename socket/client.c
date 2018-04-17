#include "unp.h"

#define INT_PORT 8090
int main(int argc, char *argv[])
{
	if (argc != 3){
		printf("number of argument error\n");
		return -1;
	}
	struct sockaddr_in clientAddr;
	int sockFd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockFd < 0){
		perror("socket");
		return -1;
	}
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(INT_PORT);
	clientAddr.sin_addr.s_addr = inet_addr(argv[1]);

	if (bind(sockFd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0){
		perror("bind");
		return -1;
	}
	if (connect(sockFd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0){
		perror("connect");
		return -1;
	}
	char buf[BUFSIZE];
	while (1){
		memset(buf, 0, sizeof(buf));
		int ret = read(0, buf, sizeof(buf));
		if (ret < 0){
			perror("read");
			return -1;
		}
		ret = send(sockFd, buf, ret, 0);
		if (ret < 0){
			perror("send");
			return -1;
		}

		printf("client send msg to server: %s\n", buf);
	}
	close(sockFd);
	return 0;
}
