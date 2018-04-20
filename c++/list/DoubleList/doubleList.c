#include "doubleList.h"

LinkedList LinkedList_Init()
{
	printf("LinkedList is init\n");

	Node *p = NULL;
	return p;	
}

int IsEmpty(LinkedList head)
{
	if (head == NULL){
		return 0;
	}else{
		return 1;
	}
}
//头插
LinkedList LinkedList_Create_Front(LinkedList head, int n)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL){
		perror("malloc");
		return NULL;
	}
	p->data = n;
	if (head == NULL){
		p->next = p;
		p->prev = p;
		return p;
	}

	Node *t = head;
	while (t->next != head){
		t = t->next;
	}
	p->next = head;
	p->prev = t;
	head->prev = p;
	t->next = p;
	return p;
}

//尾插
LinkedList LinkedList_Create_Back(LinkedList head, int n)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL){
		perror("malloc");
		return NULL;
	}
	p->data = n;

	if (head == NULL){
		p->next = p;
		p->prev = p;
		return p;
	}
	Node *t = head;
	while (t->next != head){
		t = t->next;
	}
	t->next = p;
	p->next = head;
	p->prev = t;
	head->prev = p;
	return head;
}

void LinkedList_Show(LinkedList head)
{
	Node *t = head;
	if (t == NULL){
		printf("linked is empty ,no data\n");
		return;
	}
	int count = LinkedList_Count(head);
	while (count > 0){
		printf("n = %d\n",t->data);
		t = t->next;
		count--;
	};
	printf("\n");
	return;
}

//逆序打印
void LinkedList_Inversion_Show(LinkedList head)
{
	Node *t = head;
	while (t->next != head){
		t = t->next;
	}
	if (t == NULL){
		printf("linked is empty ,no data\n");
		return;
	}
	int count = LinkedList_Count(head);
	while (count > 0){
		printf("n = %d\n",t->data);
		t = t->prev;
		count--;
	};
	printf("\n");
	return;
}

void LinkedList_Free(LinkedList head)
{
	if (head == NULL){
		printf("no data to free\n");
		return;
	}
	Node *t = head;
	int count = LinkedList_Count(head);
	while (count > 0){
		free(head);
		t = t->next;
		head = t;
		count--;
	}
}

//若有多个元素相同，返回的是第一个元素所在位置
LinkedList LinkedList_Find(LinkedList head, int pos)
{
	Node *t = head;
	while (t->next != NULL){
		if (t->data == pos){
			return t;
		}
		t = t->next;
	}
	return NULL;
}

void LinkedList_Update(LinkedList head, int pos, int data)
{
	Node *t = LinkedList_Find(head, pos);
	if (t == NULL){
		printf("no data can updata\n");
		return ;
	}
	t->data = data;

}

LinkedList LinkedList_Delete(LinkedList head, int data)
{
	Node *t = LinkedList_Find(head, data);
	if (t == NULL){
		printf("no data can delete\n");
		return ;
	}
	if (t == head){
		t->next->prev = head->next;
		t->prev->next = t->next;
		Node *tmp = t->next;
		free(t);
		return tmp;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);

	return head;
}

//在值为pos节点后插入一个data
void LinkedList_Insert(LinkedList head, int pos, int data)
{
	Node *t = LinkedList_Find(head, pos);
	if (t == NULL){
		printf("linkedList has no %d data\n",pos);
		return ;
	}
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL){
		perror("malloc");
		return;
	}
	p->data = data;

	p->next = t->next;
	t->next->prev = p;	
	t->next = p;
	p->prev = t;
}
int LinkedList_Count(LinkedList head)
{
	int count = 1;
	Node *t = head;
	if (t == NULL){
		return 0;
	}
	while (t->next != head){
		++count;
		t = t->next;
	}
	return count;
}

//时间复杂度 O(n^2) n是链表长度
void LinkedList_Sort(LinkedList head)
{
	int count = LinkedList_Count(head);
//	printf("count = %d\n",count);
	Node *t = head;
	//控制外层比较次数
	while (count > 0){
		while (t->next != head){
			int temp;
			if (t->data > t->next->data){
				temp = t->data;
				t->data = t->next->data;
				t->next->data = temp;
			}
			t = t->next;
		}
		count--;
		t = head->next;
	}
}


