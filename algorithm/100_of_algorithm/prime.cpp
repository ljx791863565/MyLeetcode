/*
   素数算法
   */

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>

#define N 100000

//最普通方法 时间复杂度 O(n * n)
void prime1(int num)
{
	int i, j, count=0;
	for (i=2; i<=num; ++i){
		for (j=2; i<=num; ++j){
			if (i % j == 0){
				break;
			}
		}
		if (i == j){
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("count = %d\n", count);
}

//如果n是一个合数，它的所有因数不超过 sqrt(n)
//时间复杂度 O(n * sqrt(n))
void prime2(int num)
{
	int i, j, count=0;
	for (i=2; i<=num; ++i){
		for (j=2; j<=sqrt(num); ++j){
			if (i % j == 0){
				break;
			}
		}
		if (j > sqrt(i)){
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("count = %d\n", count);
}

//筛选法
//所有偶数都不是素数
//所有是已知素数的倍数的数都不是素数
//时间复杂度O(n)
void prime3(int num)
{
	bool b_prime[num+1];//素数表
	int i, j, count = 0;
	//抛弃所有偶数
	for (i=0; i<=num; ++i){
		if (i % 2 == 0){
			b_prime[i] = false;
		}else{
			b_prime[i] = true;
		}
	}
	b_prime[0] = b_prime[1] = false;//0, 1 都不是素数
	b_prime[2] = true;//2是素数
	for (i=3; i<=sqrt(num); ++i){
		if (b_prime[i]){
			for (j=i+i; j<=num; j+=i){
				b_prime[j] = false;
			}
		}
	}

	for (i=2; i<= num; ++i){
		if (b_prime[i]){
			count++;
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("count = %d\n", count);
}
int main()
{
	prime3(N);
	return 0;
}
