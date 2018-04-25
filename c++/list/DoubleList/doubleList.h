#ifndef __DOUBLELIST__H__
#define __DOUBLELIST__H__
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}Node, *LinkedList;
int IsEmpty(LinkedList head);
LinkedList LinkedList_Init();
LinkedList LinkedList_Create_Back(LinkedList head, int n);
LinkedList LinkedList_Create_Front(LinkedList head, int n);
void LinkedList_Show(LinkedList head);
void LinkedList_Inversion_Show(LinkedList head);
void LinkedList_Free(LinkedList head);
int LinkedList_Count(LinkedList head);
LinkedList LinkedList_Find(LinkedList head, int pos);
void LinkedList_Update(LinkedList head, int pos, int data);
LinkedList LinkedList_Delete(LinkedList head, int data);
void LinkedList_Sort(LinkedList head);
void LinkedList_Insert(LinkedList head, int pos, int data);
#endif //__DOUBLELIST__H__

