#include <stdio.h>

void print(int n)
{
	printf("%d 整除的数是:  \n", n);
	for (int i = 1; i <= 100; i++){
		if (i % n == 0){
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main()
{
	print(3);
	print(5);
	print(7);

	return 0;
}
