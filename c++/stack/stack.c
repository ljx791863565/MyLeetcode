#include "stack.h"

//0 : 非空   1 ：空
int IsEmpty(Stack s)
{
	if (s == NULL){
		return 1;
	}else {
		return 0;
	}
}

Stack Create_Stack(Stack s)
{
	s = (Node *)malloc(sizeof(Node));
	if (s == NULL){
		perror("malloc\n");
		return NULL;
	}
	s->next = NULL;
	MakeEmpty(s);
	return s;
}

void Dispose_Stack(Stack s)
{
	if (IsEmpty(s)){
		printf("no data\n");
		return ;
	}
	Node *p = s;
	while (p->next != NULL){
		free(s);
		p = p->next;
		s = p;
	}
}

void MakeEmpty(Stack s)
{
	if (s == NULL){
		printf("must use Create_Stack first\n");
		return;
	}else{
		while (!IsEmpty(s)){
			Pop(s);
		}
	}
}

void Push(ElementType data, Stack s)
{
	Node *p =(Node*)malloc(sizeof(Node));
	if (p == NULL){
		perror("malloc");
		return ;
	}else{
		p->data = data;
		p->next = s->next;	//头插入，保持先push的在底层
		s->next = p;
	}
}

ElementType Top(Stack s)
{
	if (!IsEmpty(s)){
		return s->next->data;
	}else{
		printf("empty stack\n");
		return 0;
	}
}

void Pop(Stack s)
{
	Node *temp;
	if (IsEmpty(s)){
		printf("empty stack\n");
		return ;
	}
	temp = s->next;
	s->next = s->next->next;
	free(temp);
}


