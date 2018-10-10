#include <stdio.h>
#include <string.h>

void fun(char *str)
{
	printf("%ld\n", sizeof(str));	//8
}
int main()
{
	char str[] = "hello";
	printf("%ld\n", sizeof(str));	//6
	printf("%ld\n", strlen(str));	//5
	char *p = str;
	printf("%ld\n", sizeof(p));		//8
	fun(str);
}
