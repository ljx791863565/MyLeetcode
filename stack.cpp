#include <iostream>
#define SIZE 96

using namespace std;
class Stack{
	char s[SIZE];
	char *max;
	char *min;
	char *top;
//	void new();
public:
	void push(char);
	char pop();
};
char Stack::pop()
{
	if (top <= min)
		cout << "stack underflow" << endl;
	return *(--top);
}

void Stack::push(char ch)
{
	cout << ch << endl;
}
int main()
{
	Stack s1, s2;
	Stack *p1 = &s1;
	Stack *p2 = new Stack;

	s1.push('h');
	p2->push('s');
}
