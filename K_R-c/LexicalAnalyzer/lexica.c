#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//关键字和标识符判断
int KeyWord(char *ch)
{
	int i;
	//定义关键字集
	char ch2[32][9] = {
		"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "emum",
		"register", "typedef", "char", "extern", "return", "union", "const", "float", "short",
		"unsigned", "continue", "for", "signed", "void", "default", "goto", "sizeof", "volatile",
		"do", "while", "static", "if"
	};
	for (i=0; i<32; ++i){
		if (!strcmp(ch, ch2[i])){
			return i+1;
		}
	}
	return 47;
}

int main()
{
	FILE *fp, *fp1;
	char ch; //临时保存字符
	int rowCount = 1;//保存行数
	char inFile[20], outFile[20];
	printf("输入要扫描的文件名\n");
	scanf("%s", inFile);
	printf("输入要输出的文件名\n");
	scanf("%s", outFile);

	if ((fp = fopen(inFile, "r")) == NULL){
		perror("fopen");
		exit(0);
	}
	if ((fp1 = fopen(outFile, "w")) == NULL){
		perror("fopen");
		exit(0);
	}

	while (!feof(fp)){
		ch = fgetc(fp);
		if (ch == 10){
			rowCount++;
		}
		
		//扫描头文件及预留字
		if (isalpha(ch) || ch == '_'){
			int i = 0;
			char ch1[30];
			ch1[i++] = ch;
			while (!feof(fp)){
				ch = fgetc(fp);
				if (ch == 10){
					rowCount++;
				}
				if (isalpha(ch) || isdigit(ch) || ch == '_'){
					ch1[i++] = ch;
				}
				if (ch == '.'){
					// .h 是头文件
					ch = fgetc(fp);
					if ((ch = fgetc(fp) == 'h')){
						if (ch == 10){
							rowCount++;
							ch1[i++] = '.';
							ch1[i++] = 'h';
							ch1[i] = '\0';

							printf("line %d:	%s	83\n", rowCount, ch1);
							fprintf(fp1, "line %d:	%s	83\n", rowCount, ch1);
							break;
						}
					}else{
						//后面不是h说明是 标识符 .
						fseek(fp, -1, 1);
						ch1[i] = '\0';
						printf("line %d:	%s	%d\n", rowCount, ch1, KeyWord(ch1));
						fprintf(fp1, "line %d:	%s	%d\n", rowCount, ch1, KeyWord(ch1));
						break;
					}
				}
			}	
		}
		//扫描数字
		if (isdigit(ch) || ch == '-'){
			if (isdigit(ch)){
				printf("line %d:	%c", rowCount, ch);
				fprintf(fp1, "line %d:	%c", rowCount, ch);
				while (!feof(fp)){
					ch = fgetc(fp);
					//小数点正常打印
					if (isdigit(ch) || ch == '.'){
						printf("%c", ch);
						fprintf(fp1, "%c", ch);
					}else{
						printf("			46\n");
						fprintf(fp1, "			46\n");
						fseek(fp, -1, 1);
						ch = '\0';
						break;
					}
				}
			}
			if (ch == '-'){
				ch = fgetc(fp);
				if (ch == '-'){
					printf("line %d:	--	80\n", rowCount);
					fprintf(fp1, "line %d:	--	80\n", rowCount);
				}
				if (ch == '>'){
					printf("line %d:	->	81\n", rowCount);
					fprintf(fp1, "line %d:	->	81\n", rowCount);
				}
				//- 后面跟着数字
				if (isdigit(ch)){
					fseek(fp, -3, 1);
					ch = fgetc(fp);
					//前面也是数字
					if (isdigit(ch)){
						ch = fgetc(fp);
						//判断 - 为减号
						printf("line %d:	%c	79\n", rowCount, ch);
						fprintf(fp1, "line %d:	%c	79\n", rowCount, ch);
					}else{
						//判断 - 为负号
						ch = fgetc(fp);
						printf("line %d:	%c", rowCount, ch);
						fprintf(fp1, "line %d:	%c", rowCount, ch);
						while (!feof(fp)){
							ch = fgetc(fp);
							if (isdigit(ch) || ch == '.'){
								printf("%c", ch);
								fprintf(fp1, "%c", ch);
							}else{
								printf("			46\n");
								fprintf(fp1, "			46\n");
								fseek(fp, -1, 1);
								break;
							}
						}
					}
				}

			}
		}
		//扫描注释
		if (ch == '/'){
			ch = fgetc(fp);
			if (ch == 10){
				rowCount++;
			}
			if (ch == '/'){
				while (fgetc(fp) != 10){
					if (ch == 10){
						rowCount++;
					}
				}
			}
			if (ch == '*'){
				while (fgetc(fp)){
					ch = fgetc(fp);
					if (ch == 10){
						rowCount++;
					}
					if (ch == '*'){
						ch = fgetc(fp);
						if (ch == '/'){
							break;
						}
					}
				}
			}else{
				//输出内容为注释内容，原样打印
				printf("line %d:	/	83\n", rowCount);
				fprintf(fp1, "line %d:	/	83\n", rowCount);
				fseek(fp, -1, 1);
				break;
			}
		}
		//扫描引号
		if (ch == '"'){
			int i = 0;
			printf("line %d:	%c	82\n", rowCount, ch);
			fprintf(fp1, "line %d:	%c	82\n", rowCount, ch);
			while (!feof(fp)){
				ch = fgetc(fp);
				i++;
				if (ch == 10){
					rowCount++;
				}
				if (ch != '"'){
					//ch != ' '
					if (ch != 32){
						printf("%c", ch);
						fprintf(fp1, "%c", ch);
					}
				}else{
					//到后半个 " 结束引号内容
					break;
				}
			}
			printf("			99\n");
			fprintf(fp1, "			99\n");
			//退回到引号开始之前
			fseek(fp, -i, 1);
			for (; i>0; --i){
				ch = fgetc(fp);
				// ch == '\'
				if (ch == 92){
					char ch5[13] = {
						"abfntv\\\?\'\"\0"
					};
					ch = fgetc(fp);
					int k;
					for (k=0; k<12; k++){
						if (ch == ch5[k]){
							printf("line %d:	\\%c	%d", rowCount, ch, k+33);
							fprintf(fp1, "line %d:	\\%c	%d", rowCount, ch, k+33);
						}
					}
					if (ch == 'd' && isdigit(fgetc(fp)) && isdigit(fgetc(fp))){
						//转换为三位的八进制
						fseek(fp, -2, 1);
						printf("line %d:	%c%c	44\n", rowCount, fgetc(fp), fgetc(fp));
						fprintf(fp1, "line %d:	%c%c	44\n", rowCount, fgetc(fp), fgetc(fp));
					}
					if (ch == 'x' && isdigit(fgetc(fp)) && isdigit(fgetc(fp))){
						//转换为二位的十六进制
						fseek(fp, -2, 1);
						printf("line %d:	%c%c	45\n", rowCount, fgetc(fp), fgetc(fp));
						fprintf(fp1, "line %d:	%c%c	45\n", rowCount, fgetc(fp), fgetc(fp));
					}
				}
				if (ch == '%'){
					ch = fgetc(fp);
					char bfh[4] = {
						"dsc"
					};
					for (i=0; i<3; ++i){
						if (bfh[i] == ch){
							printf("line %d:	%%%c	83\n", rowCount, ch);
							fprintf(fp1, "line %d:	%%%c	83\n", rowCount, ch);
						}
					}
				}
			}
		}
		//扫描其他字符
		if (!isdigit(ch) && !isalpha(ch) && ch != '_' && ch != '"' && ch != '/'){
			char ch2[14] = {
				"#()[]{}'*:~%^"
			};
			char ch3[9] = {
				"+?=|&!<>"
			};
			char ch4[9] = {
				"+==|&==="
			};
			int i, j;
			for (i=0; i<13; ++i){
				if (ch == ch2[i]){
					printf("line %d:	%c	%d\n", rowCount, ch, i+48);
					fprintf(fp1, "line %d:	%c	%d\n", rowCount, ch, i+48);
				}
			}
			for (j=0; j<8; ++j){
				if (ch  == ch3[j]){
					ch = fgetc(fp);
					if (ch == ch4[j]){
						//拼成 ++ ?= == || && != >= <= 
						printf("line %d:	%c%c	%d\n", rowCount, ch3[j], ch4[j], j+69);
						fprintf(fp1, "line %d:	%c%c	%d\n", rowCount, ch3[j], ch4[j], j+69);
					}
				}
				if (ch == '<' && ch3[j] == '<'){
					printf("line %d:	<<	77\n",rowCount);
					fprintf(fp1, "line %d:	<<	77\n",rowCount);
				}
				if (ch == '>' && ch3[j] == '>'){
					printf("line %d:	>>	78\n",rowCount);
					fprintf(fp1, "line %d:	>>	78\n",rowCount);
				}else{
					//为单一个符号 + ? = | & ! < >
					printf("line %d:	%c	%d\n",rowCount, ch3[j], j+61);
					fprintf(fp1, "line %d:	%c	%d\n",rowCount, ch3[j], j+61);

					fseek(fp, -1, 1);
				}
				
			}
		}
	}

	return 0;
}
