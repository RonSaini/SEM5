#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>

void* thread1(void* param)
{
    int *arr = (int*)param;
    int i,j;
    int n=arr[0];
    int sum=0;
    for(i=1;i<=n;i++)
    {
        if(arr[i]<0)
        {
            sum=sum+arr[i];
        }
    }
    return sum;
}

void main()
{
    pthread_t thread;
    int sum;
    int num;
    printf("Enter the number of elements : \n");
    scanf("%d",&num);

    int *arr = (int*)calloc(num,sizeof(int));
    arr[0]=num;

    printf("Enter the elements : \n");
    for(int i=1;i<=num;i++)
    {
        scanf("%d",&arr[i]);
    }

    pthread_create(&thread,0,&thread1,arr);
    pthread_join(thread,&sum);

    printf("The sum of negative numbers is %d ",sum);
}