/*
   1, 2, 3, 4 四个数能组成多少个互不相同且无重复数字的三位数
   */


#include <stdio.h>

int main()
{
	int i, j, k, count=0;
	for (i=1; i<=4; ++i){
		for (j=1; j<=4; ++j){
			for (k=1; k<=4; ++k){
				if (i!=k && i!=j && k!=j){
					count++;
					printf("%d%d%d ", i, j, k);
				}
			}
		}
		printf("\n");
	}
	printf("count = %d\n", count);
	return 0;
}
