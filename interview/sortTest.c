#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100000
clock_t start, stop;
double duration;

void bucketSort(int *a, int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++){
		if (max < a[i]){
			max = a[i];
		}
	}

	int *p = (int* )malloc((max + 1)*(sizeof(int)));
	for (int i = 0; i < max + 1; i++){
		p[i] = 0;
	}
	for (int i = 0; i < n; i++){
		p[a[i]]++;
	}
	for (int i = 0, j = 0; i < max + 1; i++){
		while (p[i] != 0){
			a[j++] = i;
			p[i]--;
		}
	}
	free(p);
}

void quickSort(int *a, int low, int high)
{
	int mid = a[low];
	while (low < high){
		while (low < high && a[high] >= mid){
			high--;
		}
		a[low] = a[high];

		while (low < high && a[low] < mid){
			low++;
		}
		a[high] = a[low];
	}
	a[low] = mid;
	
}

void insertionSort(int *a, int n)
{
	int tmp = 0;
	int j;
	for (int i = 0; i < n; i++){
		tmp = a[i];
		for (j = i; j > 0 && tmp < a[j-1]; j--){
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
}
void selectionSort(int *a, int n)
{
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void doubleBubbling(int *a, int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1 ; j++){
			if (a[j] > a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}
void show(int *a, int n)
{
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int array[N];
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++){
		array[i] = rand()% N + 1;
	}
	start = clock();
//	doubleBubbling(array, N);
//	selectionSort(array, N);
//	bucketSort(array, N);
//	quickSort(array, 0, N);
	insertionSort(array, N);
	stop = clock();
	show(array, N);

	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("durations = %.2f\n", duration);
	return 0;
}
