#ifndef __ORDER_LIST__H__
#define __ORDER_LIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100	//线性表存储空间的初始分配量
#define LISTINCREMENT 10	//线性表存储空间的分配增量

typedef int ElementType ;
typedef int Status;			//表示状态

typedef struct
{
	ElementType *elem;		//储存空间基地址
	int length;				//当前长度
	int listsize;			//当前分配的储存容量 sizeof(ElementType)为单位
}*SqList;

extern SqList InitList_Sq(SqList l);
extern SqList InsertList_Sq(SqList l, int pos, ElementType x);
extern SqList DeleteList_Sq(SqList l, int pos, ElementType *x);
extern void Display(SqList l);
int LocateElem_Sq(SqList l, ElementType x);
void MergeList_Sq(SqList la, SqList lb, SqList lc);

//构造一个空的线性表
SqList InitList_Sq(SqList l)
{
	l->elem = (ElementType *)malloc(LIST_INIT_SIZE * sizeof(ElementType));
	if (l->elem == NULL){
		perror("malloc");
		return NULL;
	}
	l->length = 0;
	l->listsize = LIST_INIT_SIZE;
	return l;
}

//在顺序线性表中第pos个位置之前插入新的元素x
SqList InsertList_Sq(SqList l, int pos, ElementType x)
{
	ElementType *p, *q, *newbase;
	if (pos<1 || pos >l->length+1){
		return l;
	}

	//储存空间已满，增加分配
	if (l->length >= l->listsize){
		//在elem入口重新改变malloc内存大大小
		newbase = (ElementType *)realloc(l->elem, (l->listsize + LISTINCREMENT) *sizeof(ElementType));
		if (newbase == NULL){
			perror("realloc");
			return l;
		}
		l->elem = newbase;
		l->listsize += LISTINCREMENT;
	}

	//q为插入地址
	q = &(l->elem[pos-1]);
	for (p=&(l->elem[l->length-1]); p>=q; --p){
		//把所有在插入位置之后的元素地址都右移
		*(p+1) = *p;
	}
	*q = x;			//插入元素
	++l->length;
	return l;
}

//顺序线性表l中删除第pos个元素并把值返回在x地址中
SqList DeleteList_Sq(SqList l, int pos, ElementType *x)
{
	ElementType *p, *q;
	if (pos <1 || pos >= l->length){
		return l;
	}
	p = &(l->elem[pos -1]);
	*x = *p;
	q = l->elem + l->length - 1;	//最尾元素的地址
	for (++p; q<=p; ++p)	{
		*(p-1) = *p;	//被删除元素之后的元素左移
	}
	--l->length;
	return l;
}

void Display(SqList l)
{
	int i;
	for (i=0; i<l->length-1; ++i){
		printf("%d\n", l->elem[i]);
	}
}

//在顺序线性表中查找第一个与x值一致的元素位序
//若找到，返回在l中的位置,没有找到返回0
int LocateElem_Sq(SqList l, ElementType x)
{
	ElementType *p;
	int pos = 1;
	p = l->elem;
	while (pos <= l->length && *p++ != x){
		pos++;
	}
	if (pos <= l->length){
		return pos;
	}else{
		return 0;
	}
}

//已知顺序线性表 la lb 的元素有序递减
//归并表 la lb 得到一个新的顺序线性表lc ,并且lc的元素也有序递减
void MergeList_Sq(SqList la, SqList lb, SqList lc)
{
	ElementType *pa, *pb, *pc;
	ElementType *pa_last, *pb_last;
	pa = la->elem;
	pb = lb->elem;

lc->listsize = lc->length = la->length + lb->length;	//合并后的长度
	pc = lc->elem = (ElementType *)malloc(sizeof(ElementType) * lc->length);	//分配内存
	if (pc == NULL){
		perror("malloc");
		return ;
	}
	pa_last = la->elem + la->length-1;
	pb_last = lb->elem + lb->length-1;

	while (pa <= pa_last && pb <= pb_last){
		if (*pa <= *pb){
			*pc++ = *pa++;
		}else{
			*pc++ = *pb++;
		}
	}

	while (pa <= pa_last){
		*pc++ = *pa++;	//插入la剩余的元素
	}
	while (pb <= pb_last){
		*pc++ = *pb++;
	}
}

#endif //__ORDER_LIST__H__

