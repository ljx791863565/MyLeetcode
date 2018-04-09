/*
	寻找 0-1000 素数
   */

#include <stdio.h>
#include <math.h>

#define N 100


//时间复杂度 O(n * sqrt(n))
void myPrime(int num)
{
	int i, j;
	for (i=2; i<=num; ++i){
		for (j=2; j<=sqrt(num); ++j){
			if (i % j == 0){
				break;
			}
		}
		if (j > sqrt(i)){
			printf("%d ", i);
		}
	}
	printf("\n");
}

//筛选法
void myPrime2(int num)
{
	int prime[num+1];
	int i, j;
	//注意到所有的偶数都不是素数
	for (i = 1; i< num+1; ++i){
		if (i % 2){
			prime[i] = i;
		}else{
			prime[i] = 0;
		}
	}

	for (i=3; i<=sqrt(num); ++i){
		if (prime[i]){
			for (j=i+i; j<=num; j += i){
				prime[j] = 0;
			}
		}
	}
	
	for (i=2; i<num+1; ++i){
		if (prime[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}
int main()
{
	myPrime2(N);
	return 0;
}
