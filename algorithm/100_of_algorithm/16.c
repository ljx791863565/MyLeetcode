/*
   求两数m n 的最大公约数和最小公倍数
   */


#include <stdio.h>

int main()
{
	int n, m;
	int min;
	int i, k;


	printf("输入两个整数\n");
	scanf("%d %d", &m, &n);

	min = n;
	if (min > m){
		min = m;
	}
	for (i=1; i<=min; ++i){
		if (m % i == 0 && n % i == 0){
			k = i;
		}
	}
	printf("最大公约数是 %d\n",k);
	return 0;
}
