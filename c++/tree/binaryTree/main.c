#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main()
{
	Position p;
	MakeEmpty(p);
	p = Insert(8,p);
	p = Insert(6,p);
	p = Insert(7,p);
	p = Insert(3,p);
	p = Insert(1,p);
	p = Insert(10,p);
	
//	p = Delete(1, p);

	printf("前序遍历: ");
	PreOrderTraverse(p);
	printf("\n");

	printf("中序遍历: ");
	InOrderTraverse(p);
	printf("\n");

	printf("后序遍历: ");
	PostOrderTraverse(p);
	printf("\n");

//	printf("Min element = %d\n", FindMin(p)->element);
//	printf("Max element = %d\n", FindMax(p)->element);
//
//	printf("find %d element ok\n", Find(10, p)->element);
//	printf("depth = %d\n", Depth(p));
//	printf("leaf lavel = %d\n",GetLeafLevel(p));
	return 0;
}
