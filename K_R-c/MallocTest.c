#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *ptr;
	if ((ptr = (char*)malloc(0)) == NULL){
		printf("Got a null pointer\n");
	}else {
		printf("Got a valid pointer\n");
	}
}
