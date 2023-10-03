#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int i,j,count=0;
    char str[400];
    char ch;
    int fd = open("file.txt",O_RDONLY,S_IRUSR);  
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
        printf("errorrr");
        exit(1);
    }
    else if(pid == 0)
    {
        for(i=0;i<30000;i++);
        printf("CHild process \n\n");
        int k=1;
        int j=0;
        while(k<11)
        {
            read(fd,&ch,1);
            if(ch!='\n')
            {
                str[j++]=ch;
            }
            else if(ch=='\n')
            {
                str[j]='\0';
                printf("%s \n",str);
                j=0;
                k++;
            }
        }
       // exit(0);
    }
    else
    {
        int count=0;
        printf("Parent process \n\n");
        int k=1;
        while(k<11)
        {
            read(fd,&ch,1);
            count++;
            if(ch!='\n')
            {
                str[j++]=ch;
            }
            else if(ch=='\n')
            {
                str[j]='\0';
                printf("%s \n",str);
                j=0;
                k++;
            }
        }
        if(k==11)
        {
            int gg = lseek(fd,count,SEEK_SET);
            exit(0);
        }

    


}
}