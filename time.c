#include <stdio.h>
#include <time.h>

int main()
{
	time_t timer = time(NULL);
	printf("ctime is %s", ctime(&timer));
	return 0;
}
