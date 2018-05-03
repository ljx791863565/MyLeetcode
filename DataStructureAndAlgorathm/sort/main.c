#include <stdio.h>
#define N 7
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//折半查找
//平均时间复杂度 O(log n)
int BinSearch(int *array, int x, int len)
{
	int low, high, mid;
	low = 0;
	high = len - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (x < array[mid]){
			high = mid - 1;
		}else if (x > array[mid]){
			low = mid + 1;
		}else {
			return mid;
		}
	}
	return -1;
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

//基本的冒泡排序
//时间复杂度O(n^2)
void BubbleSort(int *array, int n)
{
	int i, j;
	for (i=0; i<n; ++i){
		for(j=0; j<n-i-1; ++j){
			if (array[j] > array[j+1]){
				Swap(&array[j], &array[j+1]);
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

	BubbleSort(array, N);

	Show(array, N);
	int place = BinSearch(array, 17, N);
	printf("%d is %d\n",17, place);

	return 0;
}
