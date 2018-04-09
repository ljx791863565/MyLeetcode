#include <stdio.h>

#define dp(expr) printf(#expr " = %d\n", expr)
#define swap(int, x, y){
	int _z;\
	_z = x;\
	x = y;\
	y = _z;
}

int main()
{
	int x = 16, y = 4;
	dp(x/y);
	swap(int ,20 , 30);
	printf("x = %d, y = %d\n",x, y);
	return 0;
}
