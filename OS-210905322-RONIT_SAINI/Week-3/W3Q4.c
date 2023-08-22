#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
void main()
{
	int status;
	pid_t pid;
	pid = fork();
	if(pid == -1)
	{
		printf("\nERROR child not created\n");
	}
	else if (pid == 0) /* child process */
	{
		printf("I'm the child!\n");
		printf("process id: %d\n",getpid());
		exit(0);
	}
	else /* parent process */
	{
		printf("I'm the parent!\n");		
	}
	execl("/bin/ps","ps",NULL);
}