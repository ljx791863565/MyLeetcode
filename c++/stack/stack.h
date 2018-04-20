#ifndef __STACK__H__
#define __STACK__H__

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	ElementType data;
	struct Node *next;
}Node, *Stack;

int IsEmpty(Stack s);
Stack Create_Stack(Stack s);
void Dispose_Stack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType data, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);

#endif //__STACK__H__

