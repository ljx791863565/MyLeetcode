#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct 
{
	char id[20];
	char passwd[20];
}Pwd;
int main()
{
	/*
	FILE *fp;
	fp = fopen("passwd.txt", "w");
	if (fp == NULL){
		perror("fopen");
		return -1;
	}
	Pwd p;
	memset(&p, 0, sizeof(p));
	strcpy(p.id, "jiaxing123456`");
	strcpy(p.passwd, "138797");
	
	printf("%s %s\n", p.id, p.passwd);
	fwrite(&p, sizeof(p), 1, fp);
*/
	Pwd test;
	memset(&test, 0, sizeof(test));
	FILE *fp1;
	fp1 = fopen("passwd.txt", "r");
//	fseek(fp1, -sizeof(test), SEEK_END);
	fread(&test, sizeof(test), 1, fp1);

	printf("%s %s\n", test.id, test.passwd);
//	fclose(fp);
	fclose(fp1);
	

}
