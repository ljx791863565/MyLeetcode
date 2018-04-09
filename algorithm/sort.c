#include <stdio.h>
#include <time.h>
#include <stdlib.h>
clock_t start, stop;
double duration;
void show(int *arr, int n)
{
	for (int i=0; i<n; ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//选择排序
void sort1(int *arr, int n)
{
	for (int i=0; i<n; ++i){
		for (int j = i+1; j<n; ++j){
			if (arr[i] > arr[j]){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

//冒泡排序
void sort2(int *arr, int n)
{
	for (int i=0; i<n; ++i){
		for (int j=0; j<n-i-1; ++j){
			if (arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

//桶排序
void sort3(int *arr, int n)
{
	int max = arr[0];
	for (int i=1; i<n; ++i){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	printf("max = %d\n", max);
	int *p = (int*)malloc(max+1);
	for (int i=0; i<max+1; ++i){
		p[i] = 0;		
	}
	for (int i=0; i<n; ++i){
		p[arr[i]]++;//计算每个元素出现的次数
	}
	for (int i=0,j=0; i<max+1; ++i){
		while(p[i] != 0){
			arr[j++] = i;
			p[i]--;
		}
	}

	free(p);
}
int main()
{
	int n, i;
	printf("Input n\n");
	scanf("%d", &n);
	int arr[n];
	srand((unsigned)time(NULL));
	for (i=0; i<n; ++i){
		arr[i] = rand()%100000 +1;
	}
	show(arr,n);
	printf("after sotr: \n");
	start = clock();
	sort3(arr, n);
	stop = clock();
	show(arr,n);
	duration = ((double)(stop - start)) /CLOCKS_PER_SEC;

	printf("durations = %.2f\n", duration);
	
	return 0;
}
