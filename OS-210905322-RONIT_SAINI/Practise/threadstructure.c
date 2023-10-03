#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

typedef struct 
{
    int *arr;
    int n;
    int evensum;
    int oddsum;
}Summation;


void* thread1111(void *arg)
{
    Summation *p = (Summation*)arg;
    p->arr[3]=1424;
}

/*void* thread2222(void *arg)
{

}*/

void main()
{
    pthread_t thread1,thread2;
    Summation str;
    int n;

    printf("Enter number of elements : \n");
    scanf("%d",&str.n);

    str.arr = (int*)calloc(str.n,sizeof(int*));

    printf("Enter elements : \n");
    for(int i=0;i<str.n;i++)
    {
        scanf("%d",&str.arr[i]);
    }

    pthread_create(&thread1,0,thread1111,&str);
    pthread_join(thread1,NULL);

    printf("Enter elements : \n");
    for(int i=0;i<str.n;i++)
    {
        printf("%d\n",str.arr[i]);
    }

}