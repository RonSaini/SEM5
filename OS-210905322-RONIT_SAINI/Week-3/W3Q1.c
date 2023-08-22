/*
C Program to block a parent process, until
the child completes using a wait system call
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <sys/wait.h>

void main()
{
    // creating child and parent process
    // storing process id in `r_val`
    int status;
    printf("[*] Starting parent process\n");
    int r_val = fork();

    // switching between different processes
    switch (r_val)
    {

    // in case some error occurs in creation
    case -1:
    {
        perror("[*] fork\n");
        exit(EXIT_FAILURE);
    }
    break;

    // in case of child process
    case 0:
    {
        printf("[**] Inside child process\n");

        // Sleeping...
        /*for (int i = 0; i < 5; i++)
        {
            sleep(1);
            printf("[**] Sleeping child for %d seconds...\n", i + 1);
        }*/

        // exiting from the child program
        exit(0);
    }
    break;

    // in case of parent class
    default:
    {
        printf("[*] Waiting for child\n");
        wait(&status);
        // waiting for child process to finish executing
        //wait(NULL);
        printf("[*] Child process finished execution\n");

        // exiting from the parent program
        exit(0);
    }
    }
}