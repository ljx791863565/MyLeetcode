#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	ElementType data;
	struct Node *next;
}Node, *List;
//typedef Node *List;

int IsEmpty(List l)
{
	if (l == NULL){
		return 0;
	}else{
		return 1;
	}
}
List InitList()
{
	List head = NULL;
	return head;
}
void DestroyList(List l)
{
	if (l == NULL){
		printf("list is empty,can not destroy\n");
		return;
	}
	List tmp = l;
	while (tmp){
		free(tmp);
		l = l->next;
		tmp = l;
	}
	printf("destroy the list \n");
	return ;
}

int GetCount(List l)
{
	int count = 0;
	if (l == NULL){
		return 0;
	}
	List tmp = l;
	while (tmp){
		++count;
		tmp = tmp->next;
	}
	return count;
}
void Display(List l)
{
	if (l == NULL){
		printf("no data\n");
		return;
	}
	List tmp = l;
	while (tmp){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return;
}
List Push_Back(List l, ElementType x)
{
	List p = (List )malloc(sizeof(Node));
	p->data = x;
	p->next = NULL;

	if (l == NULL){
		l = p;
		return l;
	}
	List tmp = l;
	while (tmp->next){
		tmp = tmp->next;
	}
	tmp->next = p;
	return l;
}
List Push_Front(List l, ElementType x)
{
	List p = (List )malloc(sizeof(Node));
	p->data = x;
	if (l == NULL){
		l = p;
		p->next = NULL;
		return l;
	}	
	p->next = l;
	return p;
}
List Insert(List l, int pos, ElementType x)
{	
	List p = (List)malloc(sizeof(Node));
	p->data = x;
	int i = 0;
	List tmp = l;
	for (i=1; i<pos; ++i){
		tmp = tmp->next;
	}
	p->next = tmp->next;
	tmp ->next = p;
	return l;
}
List Search(List l, ElementType x)
{
	if (l == NULL){
		printf("no data can search\n");
		return NULL;
	}
	List tmp = l;
	while (tmp){
		if (tmp->data == x){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
List Delete(List l, ElementType x)
{
	if (l == NULL){
		return NULL;
	}
	List tmp = l;
	List prev = NULL;
	List p = Search(tmp, x);
	if (p == NULL){
		printf("no find data\n");
		return tmp;
	}
	if (p == tmp){
		tmp = tmp->next;
		free(p);
		return tmp;
	}
	while (tmp){
		prev = tmp;
		if (tmp->data != x){
			tmp = tmp->next;
		}
		prev->next = tmp->next;
		free(tmp);
		return l;
	}
	return l;
}
List Revise(List l, int pos, ElementType x)
{
	if (l == NULL){
		return NULL;
	}
	if (pos <=0 && pos >= GetCount(l)){
		return NULL;
	}
	int i = 0;
	List tmp = l;
	for (i=1; i<pos; ++i){
		tmp = tmp->next;
	}
	tmp->data = x;
	return l;
}

//获得第pos个元素放在n中
int GetElem(List l, int pos, ElementType *n)
{
	int i = 0;
	List tmp = l;
	int len = GetCount(tmp);
	if (pos <=0 || pos >= len){
		return -1;
	}
	for (i=1; i<pos; ++i){
		tmp = tmp->next;
	}
	*n = tmp->data;
	return 1;
}

List Union(List la, List lb)
{
	if (la == NULL && lb == NULL){
		printf("two empty list\n");
		return NULL;
	}
	if (la == NULL){
		return lb;
	}
	if (lb == NULL){
		return la;
	}
	int lenA = GetCount(la);
	int lenB = GetCount(lb);
//	printf("lenA = %d lenB = %d\n", lenA, lenB);
	int tmp = lb->data;
	int i = 0;
	List pTmp = la;
	for (i = 1; i <= lenB; i++){
		GetElem(lb, i, &tmp);
		pTmp = Search(la, tmp);
		if (pTmp == NULL){
			la = Push_Back(la, tmp);
		}
	}

	return la;
}
void Sort_List(List l)
{
	if (l == NULL){
		return ;
	}
	List tmp = l;
	int len = GetCount(tmp);
	int i, j;
	ElementType dataTmp;
	List p1 = NULL;
	List p2 = NULL;
	for (i=0; i<len; ++i){
		//tmp = tmp->next;
		for (j=0; j<len-i-1; ++j){
			p1 = tmp;
			p2 = tmp->next;
			if (p1->data < p2->data){
				dataTmp = p1->data;
				p1->data = p2->data;
				p2->data = dataTmp;
			}
			tmp = tmp->next;
		}
	}
}
#endif //__LIST__H__
