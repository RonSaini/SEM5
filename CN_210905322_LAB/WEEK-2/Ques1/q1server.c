/* RONIT SAINI
210905322
SECTION A 
ROLL NO 51*/


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

void sort(int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        int min = i;

        for (int j = i; j < 5; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (i != min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void main()
{
    int sd, nd, n, len, reult;
    struct sockaddr_in seradress, cliaddr;
    int buf[5];

    sd = socket(AF_INET, SOCK_STREAM, 0);
    seradress.sin_family = AF_INET;

    seradress.sin_addr.s_addr = htonl(INADDR_ANY);
    seradress.sin_port = htons(10200);

    bind(sd, (struct sockaddr *)&seradress, sizeof(seradress));

    listen(sd, 5);
    len = sizeof(cliaddr);
    pid_t pid = fork();
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
    }

    while (1)
    {
        nd = accept(sd, (struct sockaddr *)&cliaddr, &len);

        if (fork() == 0)
        {
            close(sd);
            n = read(nd, buf, sizeof(buf));
            if (n == sizeof(buf))
                printf("Receieved array successfully!!\n");
            sort(buf);
            n = write(nd, buf, sizeof(buf));
            if (n == sizeof(buf))
                printf("Sent sorted array successfully!!\n");
        }
        close(nd);
    }
}