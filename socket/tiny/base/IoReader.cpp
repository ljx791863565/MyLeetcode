#include "IoReader.h"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <cerrno>

using namespace std;

const int MAX_LENGTH = 8192;

struct rio_t
{
	int rio_fd;
	int rio_cnt;
	char *rio_bufptr;
	char rio_buf[MAX_LENGTH];
};

void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

void rio_readinitb(rio_t *rp, int fd)
{
	rp->rio_fd = fd;
	rp->rio_cnt = 0;
	rp->rio_bufptr = rp->rio_buf;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
	int cnt;

	while (rp->rio_cnt <= 0){

	}
}
