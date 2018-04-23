#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>



int main()
{
	char notation[100];
	char choice;
	do {
		printf("请输入正确的中缀表达式\n");
		printf("例如：2*3+4/3-(2+1)\n");
		scanf("%s", notation);
		if (judge(notation)){
			shift(notation);
		}else {
			printf("表达式有误\n");
		}	

		fflush(stdin);	//清空缓存区
		printf("是否继续计算 (是：Y/y， 否：N/n)\n");
		scanf("%c", &choice);
		getchar();
		system("clear");
	} while (choice == 'y' || choice == 'Y');

	return 0;
}
