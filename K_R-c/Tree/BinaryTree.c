#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
	ElementType data;
	struct Node *right;
	struct Node *left;
}Node;


