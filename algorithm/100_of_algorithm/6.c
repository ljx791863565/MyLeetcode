/*
   用 * 输出字母 C
   */

#include <stdio.h>
#include <stdlib.h>

#define N 10
int main()
{
	int i, j;
	for (i=0; i<N; ++i){
		for (j=0; j<abs(N/2 -i); ++j){
			printf(" ");
		}
		printf("**\n");
	}

	return 0;
}
