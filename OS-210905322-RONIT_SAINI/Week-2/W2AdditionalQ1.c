#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

static int comp(const void *a, const void *b)
{
    return strcmp(*(const char**)a, *(const char**)b) > 0;
}

void printDirs(char **dl, int i)
{
    int j = 0;
    qsort(dl, i, sizeof(const char*), comp);
    for(j; j<i; j++){
        printf("%s\n", dl[j]);
    }
}

int main()
{
    char dir[256];
    getcwd(dir, sizeof(dir));
    DIR *d;
    struct dirent *e;
    struct stat statbuff;
    int i;
    char **dl = (char **) malloc(sizeof(char *) * 100);
    for(i=0; i<100; i++){
        dl[i] = (char *) malloc(sizeof(char) * 256);
    }
    i = 0;
    if ((d = opendir(dir)) == NULL){
        printf("Could not open directory");
        exit(0);
    }
    chdir(dir);
    while((e = readdir(d)) != NULL){
        lstat(e->d_name, &statbuff);
        if (S_ISDIR(statbuff.st_mode)){
            if(strcmp(e->d_name, ".") != 0 && strcmp(e->d_name, "..") != 0){
                dl[i] = e->d_name;
                i++;
            }
        }
    }
    printDirs(dl, i);
}