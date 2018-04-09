#ifndef __STUDENT__H__
#define __STUDENT__H__

#include <stdio.h>
#include <stdlib.h>

struct Student{
	int id;
	char name[20];
	float score;
};

struct Stu{
	struct Student value;
	struct Stu *next;
};

extern void midShow();
extern void studentShow();
extern void teacherShow();
extern void rootShow();
extern void quitShow();
extern void defaultShow();
extern void studentSecandShow();
extern void studentRegister();
extern void studentLogin();
extern void studentQuit(); 
#endif
