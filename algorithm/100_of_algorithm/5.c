/*
   输入三个整数，按从小到大输出
   */

#include <stdio.h>

int main()
{
	int x, y, z;
	while (scanf("%d %d %d", &x, &y, &z) != EOF){
		if (x < y && y < z){
			printf("%d %d %d\n", x, y, z);
		}
		if (x < z && z < y){
			printf("%d %d %d\n", x, z, y);
		}
		if ( y < x && x < z){
			printf("%d %d %d\n", y, x, z);
		}
		if (y < z &&  z < x){
			printf("%d %d %d\n", y, z, x);
		}
		if (z < y && y < x){
			printf("%d %d %d\n", z, y, x);
		}
		if (z < x  && x < y){
			printf("%d %d %d\n", z, x, y);
		}
	}
	return 0;
}
