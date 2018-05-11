#include "unp.h"

int main(int argc, char *argv[])
{
	if (argc != 3){
		printf("参数错误\n");
		return -1;
	}
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		return -1;
	}
	SA serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[2]));
	serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

	if (connect(sockfd, (SA *)&serverAddr, sizeof(serverAddr)) < 0){
		perror("connect");
		close(sockfd);
		return -1;
	}

	pthread_t pid;
	if (pthread_create(&pid, NULL, handler, &sockfd) == NULL){
		perror("pthread_create");
		return -1;
	}
	
	char buf[BUFFSIZE];
	int choose;
	while (1){
		
	}
	return 0;
}
