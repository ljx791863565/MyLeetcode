/*
   水仙花数
   153 = 1*1*1 + 5*5*5 + 3*3*3
   */

#include <stdio.h>

#define N 1000

void narcissistic(int num)
{
	int i, count=0;
	int m, n, k;
	for (i=100; i<num; ++i){
		m = i / 100;//百位
		n = i / 10 % 10;//十位
		k = i % 10;//个位
		if (n*n*n + m*m*m +k*k*k == i){
			printf("%d\n", i);
			count ++;
		}
	}
	printf("count = %d\n", count);
}
int main()
{
	narcissistic(N);
	return 0;
}
