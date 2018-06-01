#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main(int argc, char *argv[])
{
	if (argc != 3){
		printf("Usres error\n");
		return -1;
	}

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		perror("socket\n");
		return -1;
	}
	
	struct sockaddr_in clientaddr;
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(atoi(argv[2]));
	clientaddr.sin_addr.s_addr = inet_addr(argv[1]);

}
