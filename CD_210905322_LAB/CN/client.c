#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORTNO 10200

int main()
{
	int newsockfd,result,n=1;
	struct sockaddr_in cliaddr;

	newsockfd = socket(AF_INET,SOCK_STREAM,0);

	if (newsockfd==-1)
	{
		printf("Error with socket forming");
		exit(1);
	}

	cliaddr.sin_family = AF_INET;
	cliaddr.sin_addr.s_addr = inet_addr("172.16.58.61");
	cliaddr.sin_port = htons(PORTNO);


	result = connect(newsockfd,(struct sockaddr*)&cliaddr,sizeof(cliaddr));

	if(result==-1)
	{
		printf("Error while connecting");
		exit(1);
	}

	printf("Connection established .......\n\n\n\n");

	int num;
	printf("Enter a number : ");
	scanf("%d",&num);
	write(newsockfd,&num,sizeof(num));

	int newnum;
	read(newsockfd,&newnum,sizeof(newnum));
	printf("Received number is : %d",newnum);

	//close(newsockfd);

}