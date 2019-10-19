#include <thread>
#include <iostream>

void threadFun()
{
	std::cout<<"this is the thread " << std::endl;
}
int main()
{

	std::thread t(threadFun);
	t.join();
	return 0;
}
