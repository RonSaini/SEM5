 
//4
 
#include <pthread.h>
#include <stdio.h>
int sum=0,sum2=0;
void* child_thread( void * param )
{
	int id = (int)param;
	if(id%2==0)
	sum+=id;
	else
	sum2+=id;
	return (void *)id;
}
int main()
{
	pthread_t thread,thread2;
	int return_value,return_value2;
	printf("enter the number of elements\n\n");int a,b;
	scanf("%d",&a);
    printf("Enter elements : ");
	for ( int i=0; i<a; i++)
	{
		scanf("%d",&b);
		if(b%2==0)
		{
			pthread_create( &thread, 0, &child_thread, (void*)b );
 
		}
		else
		{
			pthread_create( &thread2, 0, &child_thread, (void*)b );
		}
	}
	pthread_join( thread, (void**)&return_value );
	pthread_join( thread2, (void**)&return_value2 );
	printf("Sum of even is:%d\n",sum);
	printf("Sum of odd is:%d\n",sum2);
}