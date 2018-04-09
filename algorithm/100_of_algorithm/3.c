/*
   100000以内判断一个数满足加上100是完全平方数，再加上168也是完全平方数
   */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int i;
	int count = 0;
	int x, y;
	for (i=1; i<=100000; ++i){
		x = sqrt(i+100);
		y = sqrt(i+268);
		if (x * x == i+100 && y * y == i+268){
			printf("i = %d\n", i);
			count ++;
		}
	}
	printf("count = %d\n", count);
	return 0;
}
