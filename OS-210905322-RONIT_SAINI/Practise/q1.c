#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int main(){
	int i;
	char c[300];
	char d[300];
	char ch;
	int k=1,j=0;
	int count=0;
	int fd=open("name.txt",O_RDONLY,S_IRUSR);
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("error in creating child process");
		exit(1);
	}
	else if(pid==0){
		for(i=0;i<20000;i++);
		j=0;
		printf("child process executing\n");
		printf("%d",k);
		while(k<=21){
		read(fd,&ch,1);
		d[j++]=ch;
		count++;
		if(ch=='\n'){
			k++;
		}
		if(k==21){
			printf("%s",d);
			exit(0);
		}




	}
}
	else if(pid>0){
		//for(i=0;i<2000;i++);
		printf("parent process executing\n");
		while(k<=11){
		read(fd,&ch,1);
		c[j++]=ch;
		count++;
		if(ch=='\n'){
			k++;
		}
		if(k==11){
			printf("%s",c);
			int a=lseek(fd,count,SEEK_SET);
			exit(0);
		}



	}
}
}