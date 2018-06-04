#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t lock;
int i = 100;
void *handler1(void *arg)
{
	while (1){
		pthread_mutex_lock(&lock);
		i++;
		printf("this is pthread1 : %d\n", i);
		sleep(2);
		pthread_mutex_unlock(&lock);
	}
}
void *handler2(void *arg)
{
	while (1){
		pthread_mutex_lock(&lock);
		i--;
		printf("this is pthread2 : %d\n", i);
		sleep(1);
		pthread_mutex_unlock(&lock);
	}
}
int main()
{
	pthread_t pid1, pid2;;
	pthread_mutex_init(&lock, NULL);
	if (pthread_create(&pid1, NULL, handler1, NULL)){
		perror("pthread");
		return -1;
	}
	if (pthread_create(&pid2, NULL, handler2, NULL)){
		perror("pthread");
		return -1;
	}

	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
