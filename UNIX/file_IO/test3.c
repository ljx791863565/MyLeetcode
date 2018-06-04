#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void Users()
{
	printf("USers error\n");
}
int main(int argc, char *argv[])
{
	if (argc != 3){
		Users();
		return -1;
	}
	
	char buf[1024];
	memset(buf, 0, sizeof(buf));

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0){
		perror("openi: fd");
		return -1;
	}
	int fd1 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd1 < 0){
		perror("open: fd1");
		return -1;
	}
	int ret = read(fd, buf, 1024);
	if (ret < 0){
		perror("read");
		return -1;
	}
	ret = write(fd1, buf, ret);
	if (ret < 0){
		perror("write");
		return -1;
	}
	close(fd);
	close(fd1);

	return 0;
}
