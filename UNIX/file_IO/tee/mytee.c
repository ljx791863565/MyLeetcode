#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

#define BUFSIZE 1024

void Usage()
{
	printf("usgae filename error\n");
	printf("-a: append\n");
	exit(-1);
}

int main(int argc, char *argv[])
{
	int ch;
	int flag = O_CREAT | O_RDWR | O_TRUNC;
	off_t offset;
	int out_fd;
	char buf[BUFSIZE];
	ssize_t  ret;

	if (argc < 2 ||(strcmp(argv[1], "--help") == 0)){
		Usage();
	}
	out_fd = open(argv[argc-1], flag, 0664);
	if (out_fd < 0){
		perror("open");
		return -1;
	}
	offset = lseek(out_fd, 0, SEEK_SET);
	while ((ch = getopt(argc, argv, ":a")) != -1){
		switch (ch)
		{
			case 'a':
				offset = lseek(out_fd, -1, SEEK_END);
				break;
			case '?':
			default :
				Usage();
				break;
		}
	}

	while ((ret = read(0, buf, BUFSIZE-1)) != -1){
		buf[ret] = '\0';
		if (write(1, buf, ret+1) != ret+1){
			perror("couldn't write whole buf");
		}
		if (write(out_fd, buf, ret) != ret){
			perror("could'n write whole buf");
		}
	}
	if (ret < 0){
		perror("read");
		exit(-1);
	}
	close(out_fd);

	return 0;
}
