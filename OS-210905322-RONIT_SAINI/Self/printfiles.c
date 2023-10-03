#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

void printfiles(char* dir)
{
    struct dirent *entry;
    struct stat statbuf;
    DIR *dp;
    dp = opendir(dir);
    if(!dp)
    {
        printf("Couldnt open directory ");
        exit(1);
    }
    chdir(dir);
    while(entry=readdir(dp))
    {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
            {
                continue;
            }
            printf("%s\tinode number %ld\n\t",entry->d_name,statbuf.st_ino);
            printfiles(entry->d_name);
        }
        else
        {
            printf("%s\tinode number %ld\n",entry->d_name,statbuf.st_ino);
        }
    }
    printf("\n");
    chdir("..");
}

void main()
{
    char dir[256];
    printf("Enter filename : \n");
    scanf("%s",dir);
    printfiles(dir);
}