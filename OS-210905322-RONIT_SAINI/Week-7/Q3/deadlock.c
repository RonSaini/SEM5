/*
Creating Deadlock while accessing shared Resorce, 
by the improper use of semaphores
*/ 

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s1,s2;

void* func1(void* p)
{
	sem_wait(&s1);
	sem_wait(&s2);
	printf("Thread 1 (Deadlock Created, Thread 2 not executed)\n");
	sem_post(&s1);
}

void* func2(void* p)
{
	sem_wait(&s2);
	sem_wait(&s1);
	printf("Thread 2 (Deadlock Created, Thread 1 not executed)\n");
	sem_post(&s2);
}

int main()
{
	pthread_t t1,t2;
	sem_init(&s1,0,1);
	sem_init(&s2,0,1);
	pthread_create(&t1,0,func1,0);
	pthread_create(&t2,0,func2,0);

	pthread_join(t1,0);
	pthread_join(t2,0);

	sem_destroy(&s1);
	sem_destroy(&s2);
}