#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORTNO 8003

int main(){
	int sd;
	char buf[256];
	struct sockaddr_in sadd,cadd;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	sadd.sin_port=htons(PORTNO);
	int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
	int len=sizeof(cadd);
	char command[512]; 
	recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr *)&cadd,&len);
	sprintf(command,"echo -en %s | nc stackoverflow.com 80 > x.html",buf);
	system(command);
	return 0;
}	