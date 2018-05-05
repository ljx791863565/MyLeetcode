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
int main(int argc, char *argv[])
{
/*	
	if (argc < 3)
	{
		//argv[1] infile
		//argv[2] outfile	
		printf("参数输入有误，请依次输入需要扫描的文件名和另存为的文件名\n");
		return -1;
	}
*/	
	FILE *fp, *fp1;
	int rowCount = 1;//保存行数
	char ch;
	char inFile[15], outFile[15];
	printf("请输入要扫描的文件名\n");
	scanf("%s", inFile);

	printf("请输入要输出的文件名\n");
	scanf("%s", outFile);
	if ((fp = fopen(inFile, "r")) == NULL){
		perror("fopne");
		return -1;
	}
	if ((fp1 = fopen(outFile, "w")) == NULL){
		perror("fopen");
		return -1;
	}
	printf("\n\n**************************************************\n\n");
	printf("\t开始词法分析\n");
	printf("\n\n**************************************************\n\n");
	printf("\n\n**************************************************\n\n");
	printf("\t行号\t字符串\t特别码\n");
	printf("\n\n**************************************************\n\n");
	fprintf(fp1, "**************************************************\n");
	fprintf(fp1, "\t行号\t字符串\t特别码\n");
	fprintf(fp1, "**************************************************\n");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == 10){
			rowCount++;
		}
		//扫描字母
		if (isalpha(ch) || ch == '_'){
			int i = 0;
			char ch1[30];//假定每个标识符最长为30
			ch1[i++] = ch;
			while (!feof(fp)){
				ch = fgetc(fp);
				if (ch == 10){
					rowCount++;
				}
				if (isalpha(ch) || isdigit(ch) || ch == '_'){
					ch1[i++] = ch;
				}
				//以 .来判断头文件
				if (ch == '.'){
					// .后跟着h则判定为头文件
					if ((ch = fgetc(fp) == 'h')){
						if (ch == 10){
							rowCount++;
							ch1[i++] = '.';
							ch1[i++] = 'h';
							ch1[i] = '\0';

							printf("line %d :	%s	83\n", rowCount, ch1);
							fprintf(fp1, "line %d :	%s	83\n", rowCount, ch1);
							break;
						}
					}else{
						fseek(fp, -1, 1);//fp 回退1
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
				printf("line %d:	%c",rowCount, ch);
				fprintf(fp1, "line %d:	%c",rowCount, ch);
				while (!feof(fp)){
					ch = fgetc(fp);
					if (isdigit(ch) || ch == '.'){
						printf("%c", ch);
						fprintf(fp1, "%c", ch);
					}else{
						printf("			46\n");
						fprintf(fp1, "				46\n");
						fseek(fp, -1, 1);
						ch = '\0';
						break;
					}
				}
			}
			if (ch == '-'){
				ch = fgetc(fp);
				if (ch == '-'){
					printf("line %d:	--	80\n", rowCount);//判断为自减符 --
					fprintf(fp1, "line %d:	--	80\n", rowCount);
				}
				if (ch == '>'){
					//判断为 ->
					printf("line %d:	->	81\n", rowCount);
					fprintf(fp1, "line %d:	->	81\n", rowCount);
				}
				if (isdigit(ch)){
					fseek(fp, -3, 1);
					ch = fgetc(fp);
					if (isdigit(ch)){
						ch = fgetc(fp);
						//判断为 减号-
						printf("line %d:	%c	79\n", rowCount, ch);
						fprintf(fp1, "line %d:	%c	79\n", rowCount, ch);
					}else{
						//判断为负号 -
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
						//直到换行符出现认为注释结束
						rowCount++;
					}
				}
			}
			if (ch == '*'){
				while (!feof(fp)){
					ch = fgetc(fp);
					if (ch == 10){
						rowCount++;
					}
					if (ch == '*'){	
						if (ch = fgetc(fp) == '/'){
							break;//直到出现 */标志注释结束
						}
					}
				}
			}else{
				//原样输出
				printf("line %d:	/	83\n",rowCount);
				fprintf(fp1, "line %d:	/	83\n",rowCount);
				fseek(fp, -1, 1);
				break;
			}
		}
		//扫描引号
		if (ch == '"'){
			int i = 0;
			printf("line %d:	%c		82\n",rowCount, ch);
			fprintf(fp1, "line %d:	%c		82\n",rowCount, ch);
			while (!feof(fp)){
				ch = fgetc(fp);
				i++;
				if (ch == 10){
					rowCount++;
				}
				if (ch != '"'){
					if (ch != 32){
						printf("%c", ch);
						fprintf(fp1, "%c", ch);
					}
				}else{
					break;
				}
			}
			printf("			99\n");
			fprintf(fp1, "			99\n");
			fseek(fp, -i, 1);	//回退到引号开始
			for (; i>0; --i){
				ch = fgetc(fp);
				if (ch == 92){
					//ch 为 \ 可能是转义字符
					char ch5[13] = {"abfntv\\?'\"0"};//转义字符集
					ch = fgetc(fp);
					int k;
					for (k=0; k<12; ++k){
						if (ch == ch5[k]){
							printf("line %d:	\\%c	%d", rowCount, ch, k+33);
							fprintf(fp1, "line %d:	\\%c	%d", rowCount, ch, k+33);
						}
					}
					if (ch = 'd' && isdigit(fgetc(fp)) && isdigit(fgetc(fp))){
						//任意字符转换为三位八进制
						fseek(fp, -2, 1);
						printf("line %d:	%c%c	44\n", rowCount, fgetc(fp), fgetc(fp));
						fprintf(fp1, "line %d:	%c%c	44\n", rowCount, fgetc(fp), fgetc(fp));
					}
					if (ch = 'x' && isdigit(fgetc(fp)) && isdigit(fgetc(fp))){
						//任意字符转换为二位十六进制
						fseek(fp, -2, 1);
						printf("line %d:	%c%c	45\n", rowCount, fgetc(fp), fgetc(fp));
						fprintf(fp1, "line %d:	%c%c	45\n", rowCount, fgetc(fp), fgetc(fp));
					}
				}
				if (ch == '%'){
					ch = fgetc(fp);
					char bfh[4] = {"dcs"};
					for (i=0; i<3; ++i){
						if (bfh[i] == ch){
							printf("line %d:	%%%c	83\n", rowCount, ch);
							fprintf(fp1, "line %d:	%%%c	83\n", rowCount, ch);
						}
					}
				}
			}
		}
		//扫描其他符号
		if (!isdigit(ch) && !isalpha(ch) && ch != '_' && ch != '"' && ch != '/'){
			char ch2[14] = {"#()[]'*:~%^"};//单符号集
			char ch3[9] = {"+?=|&!<>"};
			char ch4[9] = {"+==|&==="};//双符号集
			int j;
			for (j = 0; j<13; ++j){
				if (ch == ch2[j]){
					printf("line %d:	%c	%d\n",rowCount, ch, j+48);
					fprintf(fp1, "line %d:	%c	%d\n",rowCount, ch, j+48);
				}
			}
			for (j=0; j<8; ++j){
				if (ch == ch3[j]){
					ch = fgetc(fp);
					if (ch == ch4[j]){
						printf("line %d:	%c%c	%d\n", rowCount, ch3[j], ch4[j], j+69);
						fprintf(fp1, "line %d:	%c%c	%d\n", rowCount, ch3[j], ch4[j], j+69);
					}	
					if (ch == '<' && ch3[j] == '<'){
						printf("line %d:	<<	77\n", rowCount);
						fprintf(fp1, "line %d:	<<	77\n", rowCount);
					}
					if (ch == '>' && ch3[j] == '>'){
						printf("line %d:	>>	78\n", rowCount);
						fprintf(fp1, "line %d:	>>	78\n", rowCount);
					}else{
						printf("line %d:	%c	%d\n", rowCount, ch3[j], j+61);
						fprintf(fp1, "line %d:	%c	%d\n", rowCount, ch3[j], j+61);
						fseek(fp1, -1, 1);
					}
				}
			}
		}
	} 


}
