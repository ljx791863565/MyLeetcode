#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int j = 0;
	for (int i = 0; i < 4; i++){
		fork();
		++j;
		printf("- j = %d\n", j);
	}
}
