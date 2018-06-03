#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	if (fork() > 0){
		printf("this is parent %d\n", getpid());
		//do something
	}else if (fork() == 0){
		printf("this is child %d\n", getpid());
		//do something
	}else{
		printf("fork error\n");
		exit(1);
	}
}
