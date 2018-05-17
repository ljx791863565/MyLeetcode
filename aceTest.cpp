#include <ace/ACE.h>
#include <ace/OS_NS_stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char msg[100] = {0};
	ACE_OS::sprintf(msg, "hello %s", "world!");
	cout << msg << endl;

	return 0;
}
