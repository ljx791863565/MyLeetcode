#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0){
		printf("fork error\n");
		return -1;
	}else if (pid == 0){
		printf("this is child\n");
		/*
		   do something
		   */
	}else{
		printf("this is perent:pid = %d\n", pid);
		/*
		   do something
		   */
	}
	
	return 0;
}
