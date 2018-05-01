#include <stdio.h>
#define N 7
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//选择排序，每次拿一个数与后面的数相比较大小，并且交换
//时间复杂度 O(n^2)
void Sort1(int *array, int n)
{
	int i, j;
	for (i=0; i<n; ++i){
		for (j=i+1; j<n; ++j){
			if (array[i] > array[j]){
				Swap(&array[i], &array[j]);
			}
		}
	}
}

void Show(int *array, int n)
{
	int i = 0;
	for (i=0; i<n; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main()
{
	int array[N] = {
		34, 7, 86, 17, 3, 55, 8
	};

	Sort1(array, N);

	Show(array, N);
}
