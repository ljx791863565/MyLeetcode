#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct Users
{
	char ID[20];
	char Passwd[20];
}Us;

FILE *fp;
int getUsers(Us *test)
{
	printf("input the ID:\n");
	scanf("%s", test.ID);
	printf("input the Passwd:\n");
	scanf("%s", test.Passwd);

	return 0;
}

int saveFile(Us *test)
{
	int ret = fwrite(test, sizeof(Us), fp);
}

int main()
{
	fp = fopen("users.txt", "r");
	Us us;
   	getUsers(&us);

	saveFile(&us);

	fclose(fp);
	return 0;
}
