#include "list.h"

LinkedList LinkedList_Init()
{
	printf("LinkedList is init\n");

	Node *p = NULL;
	return p;	
}

//判断链表是否是空链表 0:空链表 1：有节点
int IsEmpty(LinkedList head)
{
	if (head == NULL){
		return 0;
	}else {
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

	p->next = head;
	head = p;
	return head;
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
	p->next = NULL;
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

void LinkedList_Show(LinkedList head)
{
	Node *t = head;
	if (t == NULL){
		printf("linked is empty ,no data\n");
		return;
	}
	while (t != NULL){
		printf("n = %d\n",t->data);
		t = t->next;
	}
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
	while (t != NULL){
		free(head);
		t = t->next;
		head = t;
	}
}

//若有多个元素相同，返回的是第一个元素所在位置
LinkedList LinkedList_Find(LinkedList head, int pos)
{
	Node *t = head;
	while (t != NULL){
		if (t->data == pos){
			return t;
		}
		t = t->next;
	}
	return NULL;
}

//在节点后插入 0：插入失败 1：插入成功
int LinkedList_Insert(LinkedList head, int pos, int data)
{
	Node *t = LinkedList_Find(head, pos);
	if (t == NULL){
		printf("no %d data\n", pos);
		return -1;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	if (p == NULL){
		perror("malloc");
		return -1;
	}
	p->data = data;

	p->next = t->next;
	t->next = p;
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
		t = head->next;
		free(head);
		return t;
	}
	Node *p = head->next;
	Node *pre = NULL;

	while (p->data != data){
		pre = p;
		p = p->next;
	}

	pre->next = p->next;
	free(p);

	return head;
}

int LinkedList_Count(LinkedList head)
{
	int count = 0;
	Node *t = head;
	while (t != NULL){
		count++;
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
		while (t->next != NULL){
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

//倒置链表
//实现思路：从第二个节点到最后一个节点，依次插入到head节点后。最后把head节点变成原来head节点后一个
//原head节点放到最后并next指向NULL
LinkedList LinkedList_Inversion(LinkedList head)
{
	if (head == NULL){
		printf("linkedList has no data\n");
		return NULL;
	}
	Node *t = head->next;
	Node *p = NULL;
	while (t->next != NULL){
		p = t->next;
		t->next = p->next;
		p->next = head->next;
		head->next = p;
	}
	t->next = head;			//相当与成环
	head = t->next->next;	//新的head 成为了原来的head下一个
	t->next->next = NULL;	//断开环
	return head;
}











