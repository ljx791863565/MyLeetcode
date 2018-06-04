#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gnu/libc-version.h>
int main()
{
	//获取glibc 版本号
	const char *ptr =  gnu_get_libc_version();
	printf("glibc version : %s\n", ptr);

	return 0;
}
