#include "list.h"

int main()
{
	List head = InitList();
	if (IsEmpty(head) == 0){
		printf("empty list\n");
	}
	head = Push_Back(head, 0);
	head = Push_Back(head, 1);
	head = Push_Back(head, 2);
	head = Push_Back(head, 3);
	head = Push_Back(head, 4);
	head = Push_Back(head, 5);
	head = Push_Front(head, 6);
	head = Push_Front(head, 7);
	head = Push_Front(head, 8);
	head = Push_Front(head, 9);
	head = Push_Front(head, 10);
	Display(head);
	printf("count = %d\n", GetCount(head));
/*
   //count
	printf("count = %d\n", GetCount(head));
	//search
	List tmp = Search(head, 3);
	if (tmp){
		printf("search the data %d\n", tmp->data);
	}else{
		printf("no data\n");
	}
*/	
	//inster
	head = Insert(head, 1, 17);
	Display(head);
	printf("count = %d\n", GetCount(head));
/*
	//revise
	head = Revise(head, 2, 19);
	Display(head);


	//delete
	head = Delete(head, 9);
	Display(head);
	head = Delete(head, 10);
	Display(head);
	head = Delete(head, 100);
	Display(head);	
*/
	List lb = InitList();
	lb = Push_Back(lb, 21);
	lb = Push_Back(lb, 7);
	lb = Push_Back(lb, 12);
	lb = Push_Back(lb, 1);
	lb = Push_Back(lb, 31);

	Display(lb);
	printf("lb count = %d\n", GetCount(lb));

//	head = Union(head, lb);
	
	Sort_List(head);
	Display(head);	
	printf("count = %d\n", GetCount(head));

	DestroyList(head);
	DestroyList(lb);
	return 0;
}
