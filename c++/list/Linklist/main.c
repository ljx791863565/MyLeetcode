#include "list.h"


int main()
{
	//初始化，获取一个头指针
	Node *head = LinkedList_Init();

	head = LinkedList_Create_Front(head, 3);
	head = LinkedList_Create_Front(head, 1);
	head = LinkedList_Create_Front(head, 8);
	head = LinkedList_Create_Back(head, 12);
	head = LinkedList_Create_Back(head, 6);
	head = LinkedList_Create_Back(head, 13);
	LinkedList_Show(head);

	head = LinkedList_Inversion(head);
	LinkedList_Show(head);	
/*
	int ret = LinkedList_Insert(head, 12, 34);
	if (ret < 0){
		printf("insert fail\n");
		return 0;
	}
	LinkedList_Show(head);


	LinkedList_Update(head, 12, 22);
	LinkedList_Show(head);	

	head = LinkedList_Delete(head, 3);
	head = LinkedList_Delete(head, 8);
	head = LinkedList_Delete(head, 13);
	LinkedList_Show(head);	
	
	LinkedList_Sort(head);
	LinkedList_Show(head);	
*/	
	LinkedList_Free(head);
	return 0;
}
