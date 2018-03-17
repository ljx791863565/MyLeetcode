#ifndef __LIST__H__
#define __LIST__H__

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int elem;
	struct Node *next;
}Node;

Node* push_back(Node* head, int n)
{
	Node *p = (Node* )malloc(sizeof(Node));
	p->next = NULL;
	p->elem = n;
	if (head == NULL){
		head = p;
		return head;
	}
	Node *t = head;
	while (t->next != NULL){
		t = t->next;
	}
	t->next = p;

	return head;
}	

Node* push_front(Node* head, int n)
{
	Node* p = (Node* )malloc(sizeof(Node));
	p->elem = n;

	if (head == NULL){
		head = p;
		p->next = NULL;
		return head;
	}
	p->next = head;
	return p;
}

Node* select(Node* head, int pos)
{
	if (NULL == head){
		printf("list has no data\n");
		return NULL;
	}
	Node* t = head;
	while (t){
		if (t->elem == pos){
			return t;
		}
		t = t->next;
	}
	return NULL;
}

//update the pos data to n
Node* update(Node* head, int pos, int n)
{
	Node* p = select(head, pos);
	if (p){
		p->elem = n;
	}else{
		printf("no find the %d\n",pos);
	}
	return head;
}
void show(Node* head)
{
	while (head){
		printf("%d ", head->elem);
		head = head->next;
	}
	printf("\n");
	return ;
}

Node* deleteList(Node* head, int n)
{
	Node *p = select(head, n);
	Node *t = head;
	if (p == head){
		head = head->next;
		free(head);
		return head;
	}
	Node *pre = head;
	while (t){
		if (t == p){
			pre->next = t->next;
			free(t);
		}else{
			pre = t;
			t = t->next;
		}
	}
	return head;
}
#endif
