#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = open("text.txt",O_RDONLY,S_IRUSR);
    int fp = open("file.txt", O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    char buf[100];
    read(fd,buf,sizeof(buf));    
    write(fp,buf,sizeof(buf)); 
    close(fd);
    close(fp);  
    exit(0);
}
