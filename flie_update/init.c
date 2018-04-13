#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

void init_daemon()
{
	int pid;
	int i;

	if (pid = fork()){
		exit(0);//是父亲进程，结束父进程
	}else if(pid < 0){
		exit(1);//fork失败
	}

	//是第一子进程，后台继续执行
	setsid();//第一子进程成为新的会话组长和进程组长

	if (pid = fork()){
		exit(0);//是第一子进程，结束第一子进程
	}else if (pid < 0){
		exit(1);
	}

	///是第二子进程
	//第二子进程不再是会话组长
	for (i=0; i<NOFILE; ++i){//关闭打开的文件描述符
		close(i);
	}

	chdir("/tmp");
	umask(0);//重设文件创建掩模

	return ;
}
