#include <stdio.h>

void swap_int(int a, int b)
{
	int tmp = a;
	a = b; 
	b = tmp;
}

void swap_str(char *str1, char *str2)
{
	char *tmp = str1;
	str1 = str2;
	str2 = tmp;
}

int main()
{
	int a = 10;
	int b = 15;
	char *str_a = "hello world";
	char *str_b = "world hello";

	swap_int(a, b);
	swap_str(str_a, str_b);
	printf("%d %d %s %s\n", a, b, str_a, str_b);

	return 0;
}

