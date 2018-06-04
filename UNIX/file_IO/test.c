#include <stdio.h>
#include <stdlib.h>

#define min (m, n) ((m) < (n) ? (m) : (n))
#define mac (m, n) ((m) > (n) ? (m) : (n))
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
	
	int ch;
	FILE *fp = fopen(argv[1], "r");
	FILE *fp1 = fopen(argv[2], "w");
	while ((ch = fgetc(fp)) != EOF){
		fputc(ch, fp1);
	}

	fclose(fp);
	fclose(fp1);

	return 0;
}
