//SERVER PROGRAM
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#define PORTNO 10200

int isPresent(char ch, char character[], int index){
	for(int i = 0; i < strlen(character); i++){
		if(i == index)
			continue;
		else if(ch == character[i])
			return 1;	
	} 
	return 0;
}

int count(char ch, char buffer[]){
	int occurences = 0;
	for(int i = 0; i < strlen(buffer); i++){
		if(ch == buffer[i])
			occurences++;
	}
	return occurences;
}


int main(){
	int socket_id = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serveraddress;
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_addr.s_addr = inet_addr("172.20.10.3");
	serveraddress.sin_port = htons(PORTNO);
	
	bind(socket_id, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
	listen(socket_id, 5);
	
	while(1){
		char buffer[256];
		char result[256];
		int n = 1;
		int ind = 0;
		int unique_count = 0;
		int countf = 0;
		int client;
		int frequency[256];
		char character[256];
		struct sockaddr_in clientaddress;
		client = sizeof(client);
		int new_socket_id = accept(socket_id, (struct sockaddr*)&clientaddress, &client);
		
		read(new_socket_id, buffer, sizeof(buffer));
		
		if(strcmp(buffer, "Stop") == 0)
			break;
		 	
		for(int i = 0; i < 256; i++){
			frequency[i] = 0;
			character[i] = '\0';
			result[i] = '\0';
			
		}
		for(int i = 0; i < strlen(buffer); i++){
			if(isPresent(buffer[i], character, i) == 1){
				character[i] = '$';
				frequency[i] = -1;
			}	
			else{
				frequency[i] = count(buffer[i], buffer);
				character[i] = buffer[i];
				result[unique_count] = character[i];
				printf("%c", character[0]);
				unique_count++;
			}	
		}
		write(new_socket_id, result, sizeof(result));
		close(new_socket_id);
	}
	close(socket_id);
}










//CLIENT PROGRAM
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(){
	char buff[256];
	int n = 1;

	while(1){
		int socket_id = socket(AF_INET, SOCK_STREAM, 0);
		struct sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr("172.20.10.3");
		address.sin_port = htons(10200);
		int result = connect(socket_id, (struct sockaddr*)&address, sizeof(address));
		
	        if(result == -1){
			perror("\nClient Error");
			exit(1);
		}
			
		char str[256];
		printf("\nEnter String: ");
		scanf("%s", str);
		
		if(strcmp(str, "Stop") == 0)
			exit(1);
		
		write(socket_id, str, sizeof(str)); 
		
		read(socket_id, buff, sizeof(buff));
		puts(buff);
		close(socket_id);
	}		
}	
