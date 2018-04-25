#include "tree.h"

int main()
{
	Tree t;
	t = MakeEmpty(t);

	t = Insert(10, t);
	t = Insert(8, t);
	t = Insert(11, t);
	t = Insert(5, t);
	t = Insert(6, t);
	t = Insert(12, t);
	t = Insert(13, t);
	t = Insert(3, t);

	printf("Prev Order Traverse: ");
	PrevOnderTraverse(t);
	printf("\n");

	printf("In Order Traverse: ");
	InOnderTraverse(t);
	printf("\n");

	printf("Post Order Traverse: ");
	PostOnderTraverse(t);
	printf("\n");
}
