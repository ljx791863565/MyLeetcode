
#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

SearchTree MakeEmpty(SearchTree t)
{
	if (t != NULL){
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}
	return NULL;
}

Position FindMin(SearchTree t)
{
	if (t == NULL){
		return NULL;
	}else if (t->left == NULL){
		return t;
	}else {
		return FindMin(t->left);
	}
}

Position FindMax(SearchTree t)
{
	/*
	非递归求最大节点
	if (t != NULL){
		while (t->right != NULL){
			t = t->right;
		}

		return t;
	}

	   */
	if (t == NULL){
		return NULL;
	}else if (t->left == NULL){
		return t;
	}else {
		return FindMin(t->right);
	}
}

Position Find(ElementType x, SearchTree t)
{
	if (t == NULL){
		return NULL;
	}

	if (x < t->element){
		return Find(x, t->left);
	}else if (x > t->element){
		return Find(x, t->right);
	}else {	
		return t;
	}
}

SearchTree Insert(ElementType x, SearchTree t) 
{
	if (t == NULL){
		t = (SearchTree)malloc(sizeof(SearchTree));
		if (t == NULL){
			perror("malloc");
			return NULL;
		}
		t->element = x;
		t->right = t->left = NULL;
	}

	if (x < t->element){
		t->left = Insert(x, t->left);
	}else if(x > t->element){
		t->right = Insert(x, t->right);
	}

	return t;

}

SearchTree Delete(ElementType x, SearchTree t)
{
	if (t == NULL){
		printf("empty tree\n");
		return NULL;
	}
	SearchTree temp = Find(x, t);
	if (temp == NULL){
		printf("not find element\n");
		return NULL;
	}

	if (temp->left != NULL){
		insert(&temp->element, );
	}

}

//树的深度
int Depth(Position p)
{
	int depth = 0;
	int r, l;
	if (p){
		r = Depth(p->right);
		l = Depth(p->left);

		depth = 1 + (r > l ? r : l);
	}
	return depth;
}
int GetLeafLevel(Position p)//满叶子的数目
{
	int level = 0;
	int l, r;
	if (p){
		//有两个叶子的节点
		if (!p->left && !p->right){
			level ++;
		}
		
		l = GetLeafLevel(p->left);
		level += l;
		r = GetLeafLevel(p->right);
		level += r;
	}

	return level;
}
void PreOrderTraverse(Position p)//前序遍历
{
	if (p){
		printf("%d ", p->element);
		PreOrderTraverse(p->left);
		PreOrderTraverse(p->right);
	}
}
void InOrderTraverse(Position p) //中序遍历
{
	if (p){
		PreOrderTraverse(p->left);
		printf("%d ", p->element);
		PreOrderTraverse(p->right);
	}
}
void PostOrderTraverse(Position p)//后序遍历
{
	if (p){
		PreOrderTraverse(p->left);
		PreOrderTraverse(p->right);
		printf("%d ", p->element);
	}
}

















