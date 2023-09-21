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
	int sockfd,newsockfd,n=1,port;
	struct sockaddr_in seraddr,cliaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd==-1)
	{
		printf("Error with socket forming");
		exit(1);
	}

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("172.16.58.61");
	seraddr.sin_port = htons(PORTNO);


	if (bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1)
	{
		printf("Error couldnt bind");
		exit(0);
	}


	listen(sockfd,5);

	
while(1){
	printf("server waiting\n");

	int l=sizeof(cliaddr);

	newsockfd = accept(sockfd,(struct sockaddr*)&cliaddr,&l);


	int num;

	read(newsockfd,&num,sizeof(num));

	printf("Received number is : %d\n",num);

	int newnum;
	newnum = num +10;
	
	printf("Sending a number back\n");

	write(newsockfd,&newnum,sizeof(newnum));
}
	//printf("ghhh");
	//close(newsockfd);
	//close(sockfd);


}