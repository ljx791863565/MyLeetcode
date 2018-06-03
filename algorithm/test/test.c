#include <stdio.h>
#define N 3

//定义一个数组打印它的全排列

void print(int *arr, int n)
{
	int count = 0;
	for (int i=0; i<n; i+){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void permutation(int *arr, int N, int sub)
{
	int tmp = 0, i;
	if (sub == N-1){
		print()
	}
}
int main()
{
	int arr[N];
	for (int i=0; i<N; i++)

	print(arr, N){
		arr[i] = i+1;
	}
	permutation(arr, N, 0);
	return 0;
}
