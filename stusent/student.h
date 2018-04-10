#ifndef __STUDENT__H__
#define __STUDENT__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
typedef struct Student{
	int num;
	char name[20];
	char sex;
	int chinese;
	int math;
	int english;
	struct Student *next;
}ST;

//保存用户账号密码的结构体
typedef struct The_users{
	char id[20];
	char passwd[20];
}users;


int menu();
void Version_info();
#endif
