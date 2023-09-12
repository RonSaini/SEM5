//3
 
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
int str,end;
void* child_thread( void * param )
{
	int flag,i;
	int id = (int)param;
   while (str < end)
   {
      flag = 0;
      if (str <= 1) {
         ++str;
         continue;
      }
      for (i = 2; i <= str / 2; ++i)
       {
         if (str % i == 0) {
            flag = 1;
            break;
         }
      }
      if (flag == 0)
         printf("%d ", str);
      ++str;
   }
    return (void *)id;
}
 
int main(int argc, char *argv[])
{
	pthread_t thread;
	int return_value;
	printf("enter the starting number\n");
	scanf("%d",&str);
	printf("enter the ending number\n");
	scanf("%d",&end);
	pthread_create( &thread, 0, &child_thread, 0);
	pthread_join( thread, (void**)&return_value );
 
}
 