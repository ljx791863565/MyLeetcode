/*
	进制转换
   */
#include <stdio.h>
#include <string.h>
void DecToBin(int num)
{
	int i, count = 0;
	char str[33];
	for (i=1; i<=32; ++i){
		str[i] = '0';
	}

	i = 0;
	while (0 != num){
		str[i++] = num % 2 + '0';
		num /= 2;
	}

	i = 32;
	while (i){
		count++;
		printf("%c", str[--i]);
		if (4 == count){
			count = 0;
			printf(" ");
		}
	}
	printf("\n");
}

void BinToDec()
{
	int k, d=0, i;
	char lese[33], n;
	printf("请输入二进制\n");
	while (scanf("%s", lese) != EOF){
		if (strlen(lese) > 32 || strlen(lese) < 0){
			printf("输入有误\n");
			return;
		}
		n = strlen(lese);
		for (i=0; i<=n+1; ++i){
			if (lese[i] > '1' || lese[i] < '0'){
				printf("输入不是二进制\n");
				return ;
			}
			if (lese[i] != '\n'){
				d = d *2 + lese[i] - '0';
			}else{
				printf("转换成十进制: %d\n", d);
			}
		}
	}
	
}

void DecToHex(int num)
{

}
int main()
{
	int num;
	while (1){
//		printf("请输入一个整数\n");
		scanf("%d", &num);
//		DecToBin(num);
		BinToDec();
	}
	
	return 0;
}
