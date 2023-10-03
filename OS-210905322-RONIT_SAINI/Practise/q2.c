#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

void* func(void* param){
	int * arr=(int*)param;

	arr[0] = 10;

//	return arr;
}

int main(){
	pthread_t thread;
	//int* arr;
	int n;
	printf("enter the number:" );
	scanf("%d",&n);
	int arr[n];

	printf("enter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	pthread_create(&thread,0,&func,arr);
	pthread_join(thread,NULL);

	for(int i=0;i<n;i++){
		printf("%d, ",arr[i]);
	}




}