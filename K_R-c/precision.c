#include <stdio.h>

double distf(long n)
{
	long i;
	double x = 0.0;
	for (i = 1 ; i <= n; i++){
		x += 1 / (double)i;
	}
	return x;
}
long secendsf(double d)
{
	long i;
	double x = 0.0;
	for (i = 1; x < d; ++i){
		x += 1 / (double)i;
	}
	return i = 1;
}
int main()
{
	long t = 3600;
	double l = 20.0;
	printf("%ld secends, %f meters\n", t, distf(t));
	printf("%ld secends, %f meters\n",secendsf(l), l);
	return 0;
}
