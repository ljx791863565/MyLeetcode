
#include <stdio.h>
#include <string.h>

// (*p)[10]  二维数组作为函数参数的写法 强调指向数组的指针，并且规定数组的大小，不然指针无法移动
void Sort(char (*p)[10], int n)
{
	int i, j, tmp;
	for (i=0; i<n; i++){
		for (j=0; j<n-i-1; ++j){
			if (strcmp((p[j]), (p[j+i])) > 0){
				tmp = j;
				j = j + 1; 
				j + 1 = tmp;
			}
		}
	}
}
void Print(char (*p)[10], int n)
{
	printf("This is the fun print\n");
	int i;
	for (i=0; i<n; ++i){
		printf("%s ", p[i]);
	}
	printf("\n");
}
int main()
{
	{
		char p[3][10] = {
			"apple", "xiaomi", "suasumg"
		};
		int i = 0;
		for (i = 0; i < 3; i++){
			printf("%s ", p[i]);
		}
		printf("\n");
		Sort(p, 3);
		Print(p, 3);
	}	
}
