/*
Using semaphores to demonstrate the 
working of the sleeping barber problem
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t customer, barber;
pthread_mutex_t seat;
int free0 = 5;

void* br(void* args)
{
	while(1)
	{
		sem_wait(&customer);
		pthread_mutex_lock(&seat);

		if(free0 < 5)
			free0++;

		sleep(1);
		printf("Cutting completed : Free seats : %d\n",free0);
		sem_post(&barber);
		pthread_mutex_unlock(&seat);
	}
}

void* cr(void* args)
{
	while(1)
	{
		pthread_mutex_lock(&seat);

		if(free0 > 0)
		{
			free0--;
			printf("Customer waiting : Free seats : %d\n",free0);
			sem_post(&customer);
			pthread_mutex_unlock(&seat);
			sem_wait(&barber);
		}
		else
			pthread_mutex_unlock(&seat);
	}
}


int main()
{
	pthread_t t1,t2;
	sem_init(&barber,0,1);
	sem_init(&customer,0,1);

	pthread_mutex_init(&seat,0);
	pthread_create(&t1,0,br,0);
	pthread_create(&t2,0,cr,0);

	pthread_join(t1,0);
	pthread_join(t2,0);

	sem_destroy(&barber);
	sem_destroy(&customer);
	pthread_mutex_destroy(&seat);
}
