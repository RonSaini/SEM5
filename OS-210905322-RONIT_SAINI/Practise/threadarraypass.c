#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

void* thread1(void *arg)
{
    int *arr = (int*)arg;
    int n=arr[0];
    printf("%d",n);
    printf("in threads \n\n");
    printf("Printed elements in threads : \n\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d \n",arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]=arr[i]+10;
    }

    return arr;
}

void main()
{
    pthread_t thread;
    int n;

    printf("Enter number of elements : \n");
    scanf("%d",&n);

    int *arr = (int*)calloc(n,sizeof(int));
    arr[0]=n;

    printf("Enter elements : \n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    pthread_create(&thread,0,thread1,arr);
    pthread_join(thread,(void**)&arr);

    printf("Printed elements : \n");
    for(int i=1;i<=n;i++)
    {
        printf("%d \n",arr[i]);
    }


}