#include "mystrlen.h"

int main()
{
	char s[] = "hello world";
	size_t len = myStrlen(s);
	printf("len = %d\n", (int)len);

	return 0;
}
