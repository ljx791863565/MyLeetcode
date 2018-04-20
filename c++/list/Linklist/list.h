#ifndef __LIST__H__
#define __LIST__H__
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node, *LinkedList;
int IsEmpty(LinkedList head);
LinkedList LinkedList_Init();
LinkedList LinkedList_Create_Back(LinkedList head, int n);
LinkedList LinkedList_Create_Front(LinkedList head, int n);
void LinkedList_Show(LinkedList head);
void LinkedList_Free(LinkedList head);
LinkedList LinkedList_Find(LinkedList head, int pos);
void LinkedList_Update(LinkedList head, int pos, int data);
LinkedList LinkedList_Delete(LinkedList head, int data);
void LinkedList_Sort(LinkedList head);
int LinkedList_Insert(LinkedList head, int pos, int data);
LinkedList LinkedList_Inversion(LinkedList head);
#endif //__LIST__H__

