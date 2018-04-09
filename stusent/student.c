#include "student.h"


void midShow()
{
	printf("\t\t欢迎来到学生管理系统\n");
	printf("\n");
	printf("\t\t1.学生\n");
	printf("\t\t2.教师\n");
	printf("\t\t3.管理员\n");
	printf("\t\t4.退出");
	printf("\n");
	printf("\n");

}

void studentShow()
{
	printf("this is student\n");
	printf("\n");
	printf("\t\t1.注册\n");
	printf("\t\t2.登陆\n");
	printf("\t\t3.返回\n");
	printf("\n");
	printf("\n");
	int num;
	printf("\t\t请选择\n");
	scanf("%d", &num);
	while (1){
		switch (num){
			case 1:
				studentRegister();
				break;
			case 2:
				studentLogin();
				break;
			case 3:
				studentQuit();
				break;
			default:
				defaultShow();
		}
	}
}

void studentRegister()
{
	printf("this is student register\n");
}

void studentLogin()
{
	printf("this is student login\n");
}

void studentQuit()
{

}
void teacherShow()
{
	printf("this is teacher\n");
}

void rootShow()
{
	printf("this is root\n");
}

void quitShow()
{
	printf("系统将在3s后退出\n");
	sleep(3);
	exit(1);
}

void defaultShow()
{
	printf("输入有误，请重新输入\n");
}
