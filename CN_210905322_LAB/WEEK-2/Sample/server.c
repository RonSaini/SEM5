/* RONIT SAINI
210905322
SECTION A 
ROLL NO 51*/// SERVER
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORTNO 7002
int main()
{
    int sockfd, newsockfd, portno, clilen, n = 1;
    char buf[256];
    struct sockaddr_in seraddr, cliaddr;
    int i, value;
    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    seraddr.sin_family = AF_LOCAL;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //**
    seraddr.sin_port = htons(PORTNO);
    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    listen(sockfd, 5);
    /* pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        printf("Parent => PID: %d\n", getpid());
        printf("Waiting for child process to finish.\n");
        wait(NULL);
        printf("Child process finished.\n");
    }
    else
    {
        printf("Unable to create child process.\n");
    }*/
    
    while (1)
    {
        clilen = sizeof(clilen);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (fork() == 0)
        {
            n = read(newsockfd, buf, sizeof(buf));
            printf(" \nMessage from Client %s \n", buf);
            n = write(newsockfd, buf, sizeof(buf));
            close(newsockfd);
            exit(0);
        }
        else
            close(newsockfd);
    }
}
