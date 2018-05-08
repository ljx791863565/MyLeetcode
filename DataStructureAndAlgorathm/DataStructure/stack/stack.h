#ifndef __STACK__H__
#define __STACK__H__

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	OVERFLOW = -2,
	ERROR = -1,
	OK = 0
}Status;
typedef int SElementType;
typedef struct
{
	SElementType *base;	//在栈构造之前和销毁之后的base 的值为 NULL
	SElementType *top;	//栈顶指针
	int stacksize;		//当前栈已分配的存储空间，以元素为单位
}SqStack;
Status InitSatck(SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(SqStack &S);
int SatckLength(SqStack &S);
Status GetTop(SqStack &S, SElementType *x);
Status Push(SqStack &S, SElementType x);
Status Pop(SqStack &S, SElementType *x);
Status StackTraverse(SqStack &S, Status (*Visit()));
#endif //__STACK__H__

Status InitSatck(SqStack &S)
{
	S.base = (SElementType *)malloc(STACK_INIT_SIZE * sizeof(SElementType));
	if (S.base == NULL){
		return OVERFLOW;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack &S, SElementType *x)
{
	if (S.top == S.base){
		return ERROR;
	}
	*x = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElementType x)
{
	//栈满，追加存储空间
	if (S.top - S.base >= S.stacksize){
		S.base = (SElementType *)realloc(S.base, (S.stacksize + STACKINCREMENT) *sizeof(SElementType));
		if (S.base == NULL){
			perror("realloc");
			return OVERFLOW;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = x;
	return OK;
}

Status Pop(SqStack &S, SElementType *x)
{
	if (S.top == S.base){
		return ERROR;
	}
	*x = *(--S.top);
	return OK;
}
Status DestroyStack(SqStack &S)
{

}
