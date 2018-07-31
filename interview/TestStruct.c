#include <stdio.h>

typedef struct Object
{
	char data[3];
}object;

int main()
{
	object obj_array[3] = {
		{'a', 'b', 'c'},
		{'d', 'e', 'f'},
		{'g', 'h', 'i'}
	};

	object *pObj = obj_array;
	printf("%c %c\n", *(char*)((char*)(pObj)+2), *(char*)(pObj+2));

	return 0;
}
