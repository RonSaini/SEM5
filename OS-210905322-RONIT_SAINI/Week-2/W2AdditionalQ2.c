#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char dir[256];
    //getcwd(dir, sizeof(dir));
    printf("Dir: ");
    scanf("%[^\n]s", dir);
    DIR *d;
    struct dirent *e;
    struct stat statbuff;
    if ((d = opendir(dir)) == NULL){
        printf("Could not open directory");
        exit(0);
    }
    chdir(dir);
    int f = 0;
    while((e = readdir(d)) != NULL){
        lstat(e->d_name, &statbuff);
        if (! S_ISDIR(statbuff.st_mode)){
            printf("File name: %s\n1 to delete and 0 to continue: ", e->d_name);
            scanf("%d", &f);
            if (f == 1){
                remove(e->d_name);
                printf("File deleted\n");
            }
        }
    }
}