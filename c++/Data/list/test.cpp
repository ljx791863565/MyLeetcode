#include "list.h"
#include <iostream>
using namespace std;
int main()
{
	CSList<int> s;
	s.InsertAfter(0,1);
	const int n = s.GetCount;
	cout << n << endl;
	return 0;
}
