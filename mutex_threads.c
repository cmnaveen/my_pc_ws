#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


void* writefun(void *arg)
{
	int i;

	while(1)
	{
		pthread_mutex_lock(&lock);
		system("./capture2.sh");
		pthread_mutex_unlock(&lock);
sleep(1);
	}

	return NULL;
}

void* readfun(void *arg)
{
	int i;
	while(1)
	{
		pthread_mutex_lock(&lock);
		system("./capture.sh");
		pthread_mutex_unlock(&lock);
	sleep(1);
	}
}



int main()
{
	pthread_t thread1,thread2;

	pthread_create(&thread1,NULL,writefun,NULL);
	pthread_create(&thread2,NULL,readfun,NULL);


	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
