#include "list.h"

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLat(Position P, List L)
{
	return P-<Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X){
		p = P->Next;
	}

	return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = Find
}
