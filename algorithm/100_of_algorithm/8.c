/*
   输出乘法口诀表
   */
#include <stdio.h>

int main()
{
	int i, j;
	for (i=1; i<10; ++i){
		for (j=1; j<=i; ++j){
			int result = i*j;
			printf("%d * %d = %-3d",i, j, result);
		}
		printf("\n");
	}
	return 0;
}
