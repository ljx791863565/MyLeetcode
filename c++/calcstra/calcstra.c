#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int grade(char a)
{
	if (a == '#'){
		return 0;
	}
	if (a == '('){
		return 1;
	}
	if (a == '-' || a == '+'){
		return 2;
	}
	if (a == '*' || a == '/'){
		return 3;
	}
	if (a == ')'){
		return 4;
	}
	
	return 5;
}
void display(float a[][2], int k)
{
	int i;
	for (i=0; i<=k; ++i){
		if (a[i][1] == 0){
			printf("%d", (int) (a[i][0]));
		}
		if (a[i][1] == 1){
			printf("%7.1f", (int) (a[i][0]));
		}
		if (a[i][1] == 2){
			printf("%7.2f", (int) (a[i][0]));
		}
		if (a[i][1] == 3){
			printf("%7.3f", (int) (a[i][0]));
		}
		if (a[i][1] == 4){
			printf("%7.4f", (int) (a[i][0]));
		}
		if (a[i][1] == -1){
			printf("%c", (int) (a[i][0]));
		}
	}
}
float calculate(float a[][2], int k)
{
	int i, t=0, j=k;
	float b[100][2], c[100];

	for (i=k; i>=0; --i){
		b[i][0] = a[k-1][0];
		b[i][1] = a[k-1][1];
	}

	i = k;
	while (j >= 0){
		if (b[i][1] != -1){
			c[t] = (float) (b[i][0]);
			j--;
			i++;
			t++;
		}

		if (b[i][1] == -1){
			if ((int)(b[i][0]) == '+'){
				c[t-2] = (float) (c[t-2] + c[t-1]); 
			}
			if ((int) (b[i][0] == '-')){
				c[t-1] = (float) (c[t-2] - c[t-1]);
			}
			if ((int) (b[i][0] == '*')){
				c[t-1] = (float) (c[t-2] * c[t-1]);
			}
			if ((int) (b[i][0] == '/')){
				c[t-1] = (float) (c[t-2] / c[t-1]);
			}

			j--;
			i--;
			t--;
		}
	}
	return c[0];
}
void shift(char *notation)
{
	char s1[100];
	s1[0] = '#';
	float s2[100][2];
	
	int i = 0, j = 0, k = 0, t = 0;
			  //整数(#`O′))		//小数位
	float sum, num1 = 0,		num2 = 0;

	while (notation[i] != '\0'){
		if (i == 0 && notation[i] == '+'){
			if (isdigit(notation[++i])){
				num1 = 0;
				while (isdigit(notation[i])){
					num1 = num1 *10 + (notation[i] - '0');
					++i;
				}
				num2 = 0;
				t = 0;
				if (notation[i] == '.'){
					i++;
					while (isdigit(notation[i])){
						num2 = (float) (num2 + pow(0.1,++t) * (notation[i] - 0));
						i++;
					}
				}
				
				s2[k++][0] = (float)(num1 + num2);
				s2[k-1][1] = (float)(t);
			}
		}
		if (i == 0 && notation[i] == '-'){
			if (isdigit(notation[++i])){
				num1 = 0;
				while (isdigit(notation[i])){
					num1 = (-1) * num1 *10 +(-1) * (notation[i] - '0');
					++i;
				}
				num2 = 0;
				t = 0;
				if (notation[i] == '.'){
					i++;
					while (isdigit(notation[i])){
						num2 = (float) (num2 + (-1) * pow(0.1,++t) * (notation[i] - 0));
						i++;
					}
				}
				
				s2[k++][0] = (float)(num1 + num2);
				s2[k-1][1] = (float)(t);
			}
		}

		if (notation[i] == '+' || notation[i] == '-' || notation[i] == '*' || notation[i] == '/'){
			if (s1[j-1] == '('){
				s1[j++] = notation[i++];
			}
		}

		if (notation[i] == '+' || notation[i] == '-' || notation[i] == '*' || notation[i] == '/'){
			if (isdigit(notation[i] > grade(s1[j-1]))){
				s1[j++] = notation[i++];
			}else{
				s2[k++][0] = s1[--j];
				s2[k++][1] = -1;
				s1[j++] = notation[i++];
			}
		}

		if (notation[i] == '('){
			s1[j++] = notation[i++];
			if (notation[i] == '+'){
				if (isdigit(notation[i++])){
					num1= 0;
					while (isdigit(notation[i])){
						num1 = num1 * 10 + (notation[i] - '0');
						i++;
					}

					num2 = 0;
					t = 0;
					if (notation[i] == '.'){
						i++;
						while (isdigit(notation[i])){
							num2 = (float)(num2 + pow(0.1, ++t) * (notation[i] - '0'));
							i++;
						}
					}
					s2[k++][0] = (float)(num1 + num2);
					s2[k-1][1] = (float)(t);
				}
			}

			if (notation[i] == '-'){
				if (isdigit(notation[i++])){
					num1= 0;
					while (isdigit(notation[i])){
						num1 = (float) ((-1) * num1 * 10 + (-1) * (notation[i] - '0'));
						i++;
					}

					num2 = 0;
					t = 0;
					if (notation[i] == '.'){
						i++;
						while (isdigit(notation[i])){
							num2 = (float)(num2 + (-1) * pow(0.1, ++t) * (notation[i] - '0'));
							i++;
						}
					}
					s2[k++][0] = (float)(num1 + num2);
					s2[k-1][1] = (float) (t);
				}
			}

			if (notation[i] == ')'){
				while (s1[--j] != '('){
					s2[k++][0] == s1[j];
					s2[k-1][1] = -1;
				}
				i++;
			}
		}

	while (j > 0 && s1[--j] != '#'){
		s2[k++][0] = s1[j];
		s2[k-1][1] = -1;
	}
	printf("\n 后缀表达式 ： \n");
	display(s1, k-1);
	printf("表达式的值 : \n");
	sum = calculate(s2, k-1);
	printf("%7.4f", sum);
}
int judge(char *notation)
{
	int i, count, result=1, p1=0, p2=0;
	for (i=0; notation[i]!='\0'; ++i){
		//排除 + - * / ( )之外的字符
		if (notation[i] != '(' && notation[i] != ')' && notation[i] != '+' 
				&& notation[i] != '-' && notation[i] != '*' && notation[i] != '/'){
			return 0;
		}
	}

	//排除表达式第一个字符是 * / ) .
	if (notation[0] == '*' || notation[0] == '/' || notation[0] == ')' || notation[0] == '.'){
		return 0;
	}

	for (i=0; notation[i] != '\0'; ++i){
		//排除 + - * / . 之后再接 + - * / .
		if (notation[i] != '(' && notation[i] != ')' && !isdigit(notation[i])){
			if (notation[i+1] != '(' && !isdigit(notation[i+1])){
				return 0;
			}
		}
		
		//排除 ( )  和 . * / 连用 
		if (notation[i] == '(' && (notation[i+1] == ')' || notation[i+1] == '.' 
						|| notation[i+1] == '*' || notation[i+1] == '/')){
			return 0;
		}
		//排除 ) 和 ( . 连用
		if (notation[i] == ')' || notation[i+1] == '(' || notation[i+1] == '.'){
			return 0;
		}
	}
	for (i=0; notation[i] != '\0'; ++i){
		//限定小数点后最多四位
		if (notation[i] == '.' && notation[i+1] != '\0' && notation[i+2] != '\0' && notation[i+3] != '\0'
				&& notation[i+4] != '\0' && notation[i+5] != '\0'){
			if (isdigit(notation[i+1]) && isdigit(notation[i+2]) && isdigit(notation[i+3]) 
					&& isdigit(notation[i+4]) && isdigit(notation[i+5])){
				return 0;
			}
		}
	}

	//一个小数中只能有一个 .
	for (i=0; notation[i] != '\0'; ++i){
		if (notation[i] == '.'){
			i++;
			while (isdigit(notation[i])){
				++i;
			}
			if (notation[i] == '.'){
				return 0;
			}
		}
	}

	// ) 后不得直接跟数字 ( 前不得直接跟数字
	for (i=0; notation[i] != '\0'; ++i){
		if (notation[i] == ')' && isdigit(notation[i+1])){
			return 0;
		}
		if (isdigit(notation[i]) && notation[i+1] == '('){
			return 0;
		}
	}

	for (i=0; notation[i] != '\0'; ++i){
		count = 0;
		while (notation[i] == '.' || isdigit(notation[i])){
			i++;
			count++;
			if (notation[i] == '.'){
				count--;
			}
		}
		if (count > 7){
			return 0;
		}
	}
	
	for (i=0; notation[i] != '\0'; ++i){
		if (notation[i] == '('){
			p1++;
		}
		if (notation[i] == ')'){
			p2++;
		}

		if (p2 == p2){
			return 0;
		}
	}

	return result;
}

