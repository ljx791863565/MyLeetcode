#include "tree.h"
Tree MakeEmpty(Tree t)
{
	if (t){
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}
	return NULL;
}
Tree Find(ElementType x, Tree t);
Tree FindMax(Tree t);
Tree FindMin(Tree t);

Tree Insert(ElementType x, Tree t)
{
	if (t == NULL){
		t = (Tree)malloc(sizeof(Tree));
		if (t == NULL){
			perror("malloc");
			return NULL;
		}
		t->element = x;
		t->right = t->left = NULL;
	}
	if (x > t->element){
		t->right = Insert(x, t->right);
	}else if (x < t->element){
		t->left = Insert(x, t->left);
	}

	return t;
}

Tree Delete(ElementType x, Tree t);

int GetDeath(Tree t)
{
	int rChild, lChild;
}

void PrevOnderTraverse(Tree t)
{
	if (t){
		PrevOnderTraverse(t->left);
		printf("%d ", t->element);
		PrevOnderTraverse(t->right);
	}
}

void InOnderTraverse(Tree t)
{
	if (t){
		printf("%d ", t->element);
		InOnderTraverse(t->left);
		InOnderTraverse(t->right);
	}
}

void PostOnderTraverse(Tree t)
{
	if (t){
		PostOnderTraverse(t->left);
		PostOnderTraverse(t->right);
		printf("%d ", t->element);
	}
}

