/*
   输出国际象棋棋盘
   */

#include <stdio.h>

#define N 8
int main()
{
	int i, j;
	for (i=0; i<N; ++i){
		for (j=0; j<N; ++j){
			if ((i+j)% 2 == 0){
				printf("%c%c", 0xDB, 0xDB);
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
