#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
void main()
{
    int sockid,res,len,n=1,size;
    struct sockaddr_in addr;
    sockid=socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(6996);
    len=sizeof(addr);

    res=connect(sockid,(struct sockaddr*) &addr,len);

    if(res==-1)
    {
        perror("\nConnection Error\n");
        exit(1);
    }

    printf("Enter Size of Array : \t");
    scanf("%d",&size);
    int buf[size],pid;
    printf("\nEnter Array Elements : \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&buf[i]);
    }

    write(sockid,&size,sizeof(size));
    
    write(sockid,buf,size*sizeof(int));

    n=read(sockid,buf,sizeof(buf));

    n=read(sockid,&pid,sizeof(pid));

    printf("Child Process ID : %d\n",pid);

    printf("Sorted Array returned from Server : \n");

    for(int i=0;i<size;i++)
    {
        printf("%d ",buf[i]);
    }
}