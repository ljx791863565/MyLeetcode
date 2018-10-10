#include <stdio.h>

#define f(x) x * x
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)
int main()
{
	int a = 6;
	int b = 2;
	int c;
	c = f(a) / f(b);

	printf("c = %d\n", c);
	printf("seconds_per_year = %d\n", SECONDS_PER_YEAR);
	return 0;
}
