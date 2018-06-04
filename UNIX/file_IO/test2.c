#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Users()
{
	printf("USers error\n");
}
int main(int argc, char *argv[])
{
	if (argc != 3){
		Users();
		return -1;
	}
	
	char buf[1024];
	memset(buf, 0, sizeof(buf));

	FILE *fp = fopen(argv[1], "r");
	FILE *fp1 = fopen(argv[2], "w");
	while ((fgets(buf, 1024, fp)) != NULL){
		fputs(buf, fp1);
	}

	fclose(fp);
	fclose(fp1);

	return 0;
}
