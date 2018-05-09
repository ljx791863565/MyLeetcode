#include "stack.h"

int main()
{

//	SqStack S;
	printf("sizeod = %d\n", sizeof(S));
	InitStack(S);
	printf("%p", S->base);
	/*
	int N, e = 0;
	scanf("%d", &N);
	while (N){
		Push(S, N % 8);
		N = N / 8;
	}

	while (!StackEmpty(S)){
		Pop(S, &e);
		printf("%d", e);
	}
	*/
}
