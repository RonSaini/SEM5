/*
Implementing the Reader - Writer 
Problem using semaphores
*/ 

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t wrt;
pthread_mutex_t mutex;
int count = 1, numreader = 0;

void* writer(void* wno)
{
	sem_wait(&wrt);
	count *= 2;
	printf("Writer %d modified count to %d\n",*((int*)wno),count);
	sem_post(&wrt);
}

void* reader(void* rno)
{
	pthread_mutex_lock(&mutex);
	numreader++;

	if(numreader == 1)
		sem_wait(&wrt);

	pthread_mutex_unlock(&mutex);

	printf("Reader %d read count as %d\n",*((int*)rno),count);
	pthread_mutex_lock(&mutex);
	numreader--;

	if(numreader == 0)
		sem_post(&wrt);

	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t read[10],write[5];
	pthread_mutex_init(&mutex,0);
	sem_init(&wrt,0,1);

	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0;i<10;i++)
		pthread_create(&read[i],0,reader,&a[i]);
	
	for(int i = 0;i<5;i++)
		pthread_create(&write[i],0,writer,&a[i]);

	for(int i = 0;i<10;i++)
		pthread_join(read[i],0);

	for(int i = 0;i<5;i++)
		pthread_join(write[i],0);

	pthread_mutex_destroy(&mutex);
	sem_destroy(&wrt);
	return 0;
}