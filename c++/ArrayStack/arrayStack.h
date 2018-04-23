#ifndef __ARRAYSTACK__H__
#define __ARRAYSTACK__H__

#define MIN_ARRAY_SIZE 5
typedef int ElementType;
typedef struct ArraySatck
{
	int Capacity;
	int TopStack;
	ElementType *Array;
}Stack, *ArrayStack;

int IsEmpty(Stack s);
int IsFull(Stack s);
Stack CreatStack(int MaxElement);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
ElementType TopAndPop(Stack s);

#endif 
