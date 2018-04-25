#ifndef __TREE__H__
#define __TREE__H__

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct TreeNode
{
	ElementType element;
	struct TreeNode *right;	//right childern
	struct TreeNode *left;	//left vhildern
}*Tree;
Tree MakeEmpty(Tree t);
Tree Find(ElementType x, Tree t);
Tree FindMax(Tree t);
Tree FindMin(Tree t);

Tree Insert(ElementType x, Tree t);	
Tree Delete(ElementType x, Tree t);

int GetDeath(Tree t);
void PrevOnderTraverse(Tree t);
void InOnderTraverse(Tree t);
void PostOnderTraverse(Tree t);
#endif //__TREE__H__

