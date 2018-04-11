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
here:
	printf("请输入二进制\n");
	while (scanf("%c", &n) != EOF){
		if (n > '1' || n < '0'){
			if (n != '\n'){
				gets(lese);
				goto here;
			}
		}
		if (n != '\n'){
			d = d *2 + n - '0';
		}else{
			printf("转换成十进制: %d\n", d);
			d = 0;
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
