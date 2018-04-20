#include "stack.h"

int main()
{
	Stack s;
	Create_Stack(s);	

	Push(3, s);
	Push(4, s);
	Push(5, s);
	Push(6, s);

	printf("top = %d\n",Top(s));

	Pop(s);
	printf("top = %d\n",Top(s));

}
