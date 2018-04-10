#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

typedef struct Student{
	int num;
	char name[20];
	char sex;
	int chinese;
	int math;
	int english;
	struct Student *next;
}ST;

int menu()
{
	char n;
	do {
		system("clear");
		printf("|--------------------------------------------|\n");
		printf("|		学生管理系统		|\n");
		printf("|--------------------------------------------|\n");
		printf("|		1.登录			|\n");
		printf("|		2.注册			|\n");
		printf("|		3.退出			|\n");
		printf("|--------------------------------------------|\n");
		
		printf("请选择(1~3): ");
		n = getchar();
	}while (n <'0' || n > '3');

	return n-48;
}

void Version_info()
{
	printf("\n\n\n\t学生信息管理系统\n\n");
	printf("\t版本号 V1.0\n");
	printf("\n\t2018.4.10\n");
	printf("\n\tnick\n\n");
}


//创建存储用户账号密码的文件
void CreateFile()
{
	FILE *fp;
	if ((fp = fopen("users.txt", "rb")) == NULL){
		if ((fp = fopen("users.txt", "wb+")) == NULL){
			perror("fopne");
		}
	}
}
void Login()
{
	users a, b;
	FILE *fp;
	if ((fp = fopen("users.txt", "r")) == NULL){
		perror("fopen");
		return ;
	}
	fread(&b, sizeof(users), 1, fp);
	printf("请输入账号\n");
	scanf("%s", a.id);
	while (1)
	{
		if (strcmp(a.id, b.id) == 0){
			break;
		}else{
			if (!feof(fp)){
				fread(&b, sizeof(users), 1, fp);
			}else{
				printf("用户名不存在\n");
				fclose(fp);
				return ;
			}
		}	
	}

	printf("请输入密码\n");
	scanf("%s", a.passwd);
	//密码匹配
	int count = 3;
	while (count){
		if (strcmp(a.passwd, b.passwd) == 0){
			fclose(fp);
			/*
			   do samething...
			 */
		}else{
			printf("密码不正确,请重新输入\n");
			count--;
		}
	}
	printf("三 次输入错误，请三秒后再试\n");
	sleep(3);
}

void InputUsers(users *u)
{
	char tmp1[20], tmp2[20];
	while (1){
		printf("请输入账号\n");
		scanf("%s", u->id);
		printf("请输入密码\n");
		scanf("%s", tmp1);
		printf("请再次输入密码\n");
		scanf("%s", tmp2);

		if (strcmp(tmp1, tmp2)){
			printf("两次输入密码不一致，请重新输入\n");
		}else{
			break;
		}
	}
	strcpy(u->passwd, tmp1);
	printf("%s %s\n", u->id, u->passwd);
	sleep(1);
}
void Register(ST* head)
{
	users a, b;
	ST stu, tmp;
	FILE *fp, fp2;
	fp = fopen("users.txt", "r");

	//读取账号信息
	fread(&a, sizeof(struct The_users), 1, fp);
	InputUsers(&b);
	while (1){
		if (strcmp(a.id, b.id)){
			//到文件末尾
			if (!feof(fp)){
				fread(&a, sizeof(users), 1, fp);
			}else{
				break;
			}
		}else{
			printf("此用户名已存在\n");
			fclose(fp);
			return ;
		}
	}
	//fp = fopen("user.txt", "a");
	fwrite(&b, sizeof(users), 1, fp);

	fp = foprn("studentInfo", "r");
	//读取学生信息
	fread(&tmp, sizeof(ST), 1, fp2);

	printf("请输入学号\n");
	scanf("%d", &stu.num);
	printf("请输入姓名\n");
	scanf("%s", stu.name);
	printf("请输入性别\n");
	scanf("%c", &stu.sex);
/*	while (1){
		if (strcmp(stu.num, tmp.num)){
			//到文件末尾
			if (!feof(fp)){
				fread(&tmp, sizeof(ST), 1, fp2);
			}else{
				break;
			}
		}else{
			printf("此学号已存在\n");
			fclose(fp2);
			return ;
		}
	}
*/
	printf("账号注册成功\n");
	head = push_back(ST* head, &stu);
	SaveToFile(head);
	fclose(fp);
	fclose(fp2);
}

ST *push_back(ST* head, ST *stu)
{
	ST *p = (ST*)malloc(sizeof(ST));
	p->next = NULL;

	p->num = stu->num;
	p->name = stu->name;
	p->sex = stu->sex;
	p->chinese = stu->chinese;
	p->math = stu->math;
	p->english = stu->english;

	if (head == NULL){
		head = p;
		return head;
	}
	ST *tmp = haed;
	while (tmp->next){
		tmp = tmp->next;
	}
	tmp->next = p;
	return head;
}

void ShowStudentInfo(ST* head)
{
	ST* tmp = head;
	if (tmp == NULL){
		printf("没有学生数据\n");
	}
	while (tmp){
		printf("");
	}
}
void SaveToFile(ST* head)
{
	FILE *fp = fopen("studentInfo", "r+");
	if (!fp){
		perror("fopen");
		return ;
	}
	ST* tmp = head;
	while (tmp->next){
		fwrite(tmp, sizeof(ST), 1, fp);
		tmp = tmp->next;
		printf("%d %s %c %d %d %d\n",tmp->num, tmp->name, tmp->sex, tmp->chinese, tmp->math, tmp->english);
	}
}


