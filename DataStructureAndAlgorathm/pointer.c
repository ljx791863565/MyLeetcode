#include <stdio.h>

int main()
{
	int a = 100;
	int *p = &a;
	printf("a = %p &a = %p\n",&a, p);

	*p = 40;
	printf("a = %p &a = %p\n",&a, p);
	printf("a = %d\n",a);
	int b = *p;
	printf("b = %d\n", b);
	return 0;
}
