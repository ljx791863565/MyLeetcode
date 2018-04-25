#ifndef __BINARYTREE__H__
#define __BINARYTREE__H__

typedef int ElementType;
typedef struct BinaryTree
{
	ElementType element;
	struct BinaryTree *right;
	struct BinaryTree *left;
}*SearchTree, *Position;

SearchTree MakeEmpty(SearchTree t);
Position Find(ElementType x, SearchTree t);
Position FindMin(SearchTree t);
Position FindMax(SearchTree t);
SearchTree Insert(ElementType x, SearchTree t);
SearchTree Delete(ElementType x, SearchTree t);
ElementType Retrieve(Position p);
SearchTree CreateTree(SearchTree t);
int GetLeafLevel(Position p);//树的深度
int Depth(Position p);
void PreOrderTraverse(Position p);//前序遍历
void InOrderTraverse(Position p); //中序遍历
void PostOrderTraverse(Position p);//后序遍历
#endif //__BINARYTREE__H__
