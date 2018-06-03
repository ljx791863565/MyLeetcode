#include "unp.h"

void *handler(void *arg)
{

}
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
	struct sockaddr_in serverAddr;
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
	if (pthread_create(&pid, NULL, handler, &sockfd)<0){
		perror("pthread_create");
		return -1;
	}
	
	char buf[BUFSIZE];
	int choose;
	int ret;
	while (1){
		memset(&buf, 0, sizeof(buf));
		ret = read(0, buf, BUFSIZE);
		ret = write(sockfd, buf, ret);
	}
	pthread_join(pid, NULL);
	close(sockfd);
	return 0;
}
