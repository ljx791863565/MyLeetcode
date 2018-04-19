#include "head.h"
void *handler(void *arg)
{
	int fd = *((int*)arg);
	char buf[BUFSIZE];
	MSGHEAD_T msghead;

	while (1){
		memset(buf, 0, sizeof(buf));
		int ret = read(fd, buf, sizeof(buf));
		if (ret < 0){
			perror("read from client");
			return;
		}

		memset(&msghead, 0, sizeof(msghead));
		memcpy(&msghead, buf, sizeof(msghead));

		msghead.len = ntohl(msghead.len);
		msghead.msgtype = ntohl(msghead.msgtype);
		msghead.result = ntohl(msghead.result);

		//注册的返回消息
		if (msghead.msgtype == 2){
			register_result(msghead.result);
		}else if (msghead.msgtype == 4){
			login_result(msghead.result);//登录返回消息判断
		}else if (msghead.msgtype == 6){
			if (msghead.len == sizeof(msghead)){
				printf("no data\n");
			}else {
				printf("%s\n", buf + sizeof(msghead));//查询的返回消息
			}
		}
	}

	return ;

}
int main(int argc, char *argv[])
{
	if (argc != 3){
		printf("number of arguments error\n");
		return -1;
	}

	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		return -1;
	}
	
	struct sockaddr_in serverAddr;
	memset(&serverAddr, 0 , sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(argv[2]));
	serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

	if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
		perror("connect");
		return -1;
	}

	pthread_t pid;

	if ( pthread_create(&pid, NULL, handler, &sockfd) < 0){
		perror("pthread_create");
		return -1;
	}
	int choose;
	char buf[BUFSIZE];
	while (1){
		printf_menu();//显示界面
		scanf("%d", &choose);
		switch (choose)
		{	
			case 1:
				myRegister();
				break;
			case 2:
				myLogin();
				break;
		}
	}
}
