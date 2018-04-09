#ifndef __STUDENT__H__
#define __STUDENT__H__

#include <stdio.h>
#include <stdlib.h>

struct Student{
	int id;
	char name[20];
	int age;
	char sex;
	float score;
};

struct Stu{
	struct Student value;
	struct Stu *next;
};


#endif
