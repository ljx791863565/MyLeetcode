/*
   因数分解
   打印出 
   90 = 2 * 3 *3 * 5 
   */


#include <stdio.h>

void myFactorization(int num)
{
	int i, j, n;
	n = num;
	for (i=2; i<=num; ++i){
		while (n != i){
			if (n % i == 0){
				printf("%d * ",i);
				n = n / i;
			}else{
				break;
			}
		}
	}
	printf("%d  =%d\n",n, num);
}
int main()
{
	int num;
	printf("输入一个整数\n");
	scanf("%d", &num);
	myFactorization(num);
	return 0;
}
