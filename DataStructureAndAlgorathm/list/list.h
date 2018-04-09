#ifndef LIST__H__
#define LIST__H__

#include <stdio.h>
#include <stdlib.>

typedef struct Node{
	int num;
	struct list *next;
}link;

extern list* push_back(list* hard, int n);
extern list* push_front(list* hard, int n);
#endif
