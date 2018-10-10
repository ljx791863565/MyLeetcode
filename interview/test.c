#include <stdio.h>

int main()
{
	int a[3][2] = {
		0, 1, 2, 3, 4, 5
	};
	int *p = a[0];
	printf("%d\n", p[0]);
	
//	int *p1 = a[];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
