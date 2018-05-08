#include "orderList.h"

int main()
{

	SqList l;		//定义顺序线性表
	InitList_Sq(l);

	InsertList_Sq(l, 1, 10);
	InsertList_Sq(l, 2, 20);
	InsertList_Sq(l, 3, 30);
	InsertList_Sq(l, 4, 40);

	printf("插入后\n");
	Display(l);

	InsertList_Sq(l, 3, 100);
	printf("插入后\n");

	ElementType x;
	DeleteList_Sq(l, 3, &x);
	printf("删除后\n");
	Display(l);
	printf("被删除元素: %d\n", x);

	SqList la, lb, lc;
	InitList_Sq(la);
	InsertList_Sq(la, 1, 3);
	InsertList_Sq(la, 2, 5);
	InsertList_Sq(la, 3, 8);
	InsertList_Sq(la, 4, 11);
	printf("la :");
	Display(la);

	InitList_Sq(lb);
	InsertList_Sq(lb, 1, 2);
	InsertList_Sq(l, 2, 6);
	InsertList_Sq(lb, 3, 8);
	InsertList_Sq(lb, 4, 9);
	InsertList_Sq(lb, 5, 11);
	InsertList_Sq(lb, 6, 15);
	InsertList_Sq(lb, 7, 20);
	printf("lb :");
	Display(lb);

	InitList_Sq(lc);
	MergeList_Sq(la, lb, lc);
	printf("merge : ");
	Display(lc);

	printf("\n");
	int a = LocateElem_Sq(lc, 5);
	printf("%d\n", a);

	return 0;

}
