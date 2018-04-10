#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	if ((fp = fopen("id.txt", "r")) == NULL){
		perror("fopen");
		return -1;
	}
	char id[20], passwd[20];
	/*
	printf("Input the passwd\n");
	scanf("%s", passwd);
	*/

	char str2[20];
	char tmp[20];
	memset(tmp, 0, sizeof(tmp));
	fread(tmp, 1, sizeof(tmp), fp);
	printf("%s\n", tmp);

	fclose(fp);

	return 0;
}
