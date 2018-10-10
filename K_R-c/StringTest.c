#include <stdio.h>

int main()
{
	char a[] = "ABCDEF";
	char b[] = {
		'A', 'B', 'C', 'D', 'E', 'F'
	};

	printf("sizeof(a) = %lu, sizeof(b) = %lu\n", sizeof(a), sizeof(b));

	return 0;
}
