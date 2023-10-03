#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int i,j=0,count;
    char str[300];
    char ch;
    int fd = open("file.txt",O_RDONLY,S_IRUSR);
    while(read(fd,&ch,1)!=0)
    {
        if(ch=='\n')
        {
            str[j]='\0';
            printf("%s \n",str);
            j=0;
        }
        else
        {
            str[j++]=ch;
        }
    }
}