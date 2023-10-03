#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

typedef struct{
	int* arr;
	int evensum;
	int oddsum;
	int n;
}array;


void* func1(void* param){
	array* a=(array*)param;

	int i,sum=0;
	for(i=0;i<a->n;i++){
		if(a->arr[i]%2!=0){
			sum+=a->arr[i];
		}
	}

	a->oddsum=sum;

}

void* func2(void* param){
	array* a=(array*)param;
	int i,sum=0;
	for(i=0;i<a->n;i++){
		if(a->arr[i]%2==0){
			sum+=a->arr[i];
		}
	}

	a->evensum=sum;



}

int main(){
	pthread_t thread1, thread2;
    array a;
    printf("enter the number of elements: ");
    scanf("%d",&a.n);
    int i;
    a.arr=(int*)malloc(a.n*sizeof(int));
    printf("enter the elements: ");
    for(i=0;i<a.n;i++){
    	scanf("%d",&a.arr[i]);
    }

    pthread_create(&thread1,0,&func1,&a);
    pthread_create(&thread2,0,&func2,&a);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("sum of odd elements is %d \n",a.oddsum);
    printf("sum of even elements is %d \n",a.evensum);



}

