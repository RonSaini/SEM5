/*
Producer-Consumer Code where producer can produce 
at most 10 more items that consumer has consumed
*/ 

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int buff[5],f,r;
sem_t mutex,full,empty;

void* producer(void* args)
{
	for(int i=0;i<10;i++)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("Produced item is : %d\n",i);
		buff[(r++)%10] = i;
		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	}
}

void* consumer(void* args)
{
	int item;
	for(int i=0;i<10;i++)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		item = buff[(f++)%10];
		printf("Consumed item is %d\n",item);
		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	}
}

int main()
{
	pthread_t t1,t2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,1);
	sem_init(&empty,0,10);

	pthread_create(&t1,0,producer,0);
	pthread_create(&t2,0,consumer,0);

	pthread_join(t1,0);
	pthread_join(t2,0);
}