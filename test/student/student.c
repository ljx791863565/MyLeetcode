#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct
{
	char ID[20];
	char Passwd[20];
}Users;
typedef struct 
{
	int id;
	char name[20];
	int age;
	char sex;
	int score;
}Student;
void print_menu()
{
//	system("clear");
	printf("\t学生管理系统\n\n\n");
	printf("\t\t1.注册\n");
	printf("\t\t2.登录\n");
	printf("\t\t3.退出\n");
	printf("\n\n\n");
	printf("请选择:");
}

int isIDok(char *id)
{
	FILE *fp;
	fp = fopen("passwd.txt", "r");
	if (fp == NULL){
		perror("fopen");
		return -1;
	}
	Users test;
	int ret;
	memset(&test, 0, sizeof(test));
	while (1){
		ret = fread(&test, sizeof(test), 1, fp);
		if (ret <= 0){
			perror("fread");
			return -1;
		}
		if (test.)

	}
}
void Register()
{
	system("clear");
	printf("this is register...\n");
	Users use;
	printf("请输入账号\n");
	scanf("%s", use.ID);
	printf("请输入密码\n");
	scanf("%s", use.Passwd);
	if (isIDok(use.ID)){
		printf("注册成功\n");
		user_save(Users *p);
	}else {
		printf("账号已存在\n");
	}
}

void Login()
{
	system("clear");
	printf("this is login...\n");
	printf("请输入账号\n");
}
