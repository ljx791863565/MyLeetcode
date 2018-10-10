#include <stdio.h>

int main()
{
	int a[5] = {
		1, 2, 3, 4, 5
	};
	int *p1 = (int*)(&a + 1);
	int *p2 = (int*)(a + 1);

	printf("%d\n", *(p1 - 1));
	printf("%d\n", *(p2 - 1));

	return 0;
}
