#include "list.h"

LinkedList LinkedListInit()
{
	Node * p = (Node *)malloc(sizeof(Node));
	if (p == NULL){
		perror("malloc");
	}

	p->next = NULL;
}

LinkedList LinkenList_Create_Front()
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	int n;
	while (scanf("%d", &n) != EOF){
		Node *p = (Node *)malloc(Node);
		p->data = n;
		p->next = head->next;
		head->next = p;
	}
	return head;
}

LinkedList LinkedList_Create_Back()
{
	Node *head = (Node *)malloc(Node);
	head->next = NULL;
	Node *t = head;
	int n;
	while (scanf("%d", &n) != EOF){
		Node *p = (Node *)malloc(sizeof(Node));
		p->data = n;
		t->next = p;
		t = p;
	}
}
