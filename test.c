#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	int b;
	//栈区内存空间向下
	printf("a = %p, b = %p\n",&a, &b);

	int *p1 = (int *)malloc(sizeof(int) *10);
	int *p2 = (int *)malloc(sizeof(int) *10);

	//堆区内存空间向上
	printf("p1 = %p , p2 = %p\n",p1, p2);
	return 0;
}
