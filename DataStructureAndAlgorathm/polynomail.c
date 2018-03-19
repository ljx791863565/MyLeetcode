/*
   有多项式f(n)， 求其值
   */

#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXK 1e7  //1000000
#define MAXN 10

clock_t start, stop;
double duration;

double fun1(int n, double *arr, double x)
{
	int i;
	double p = arr[n];
	for (i=n; i>0; --i){
		p = arr[i] + x * p;
	}

	return p;
}

double fun2(int n, double *arr, double x)
{
	int i;
	double p = arr[0];
	for (i=1; i<=n; ++i){
		p += arr[i] * pow(x, i);
	}
	return 0;
}

int main()
{
	int i;
	double arr[MAXN];//九阶多项式
	for (i=0; i<MAXN; ++i){
		arr[i] = (double)i;
	}

	start = clock();
	//程序运行太快，机器无法捕捉到ticks，所以让程序重复运行MAXK次，以便于ticks足够大到系统能显示
	for (i=0; i<MAXK; ++i){
		fun1(MAXN-1, arr, 1.1);
	}
	stop = clock();
	duration = ((double)(stop - start)) / CLOCKS_PER_SEC / MAXK;
	printf("duration1 = %6.2e\n",duration);
	printf("ticks1 = %f\n",(double)(stop -start));

	start = clock();
	for (i=0; i<MAXK; ++i){
		fun2(MAXN-1, arr, 1.1);
	}
	stop = clock();
	printf("ticks2 = %f\n",(double)(stop -start));
	duration = ((double)(stop - start)) / CLOCKS_PER_SEC / MAXK;
	printf("duration2 = %6.2e\n",duration);

	return 0;
}
