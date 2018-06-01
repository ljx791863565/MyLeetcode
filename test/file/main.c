#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct Users
{
	char ID[20];
	char Passwd[20];
}*Users;

int getUsers(Users *test)
{
	USers test;
	printf("input the ID:\n");
	scanf("%s", test->ID);
	printf("input the Passwd:\n");
	scanf("%s", test->Passwd);

	return 0;
}

int saveFile(FILE *fp, Users *test)
{
	int ret = fwrite(test, sizeof(struct Users), fp);
}

int main()
{
	FILE *fp = fopen("users.txt", "r");
	Users us;
   	getUsers(&us);

	saveFile(fp, &us);

	fclose(fp);
	return 0;
}
