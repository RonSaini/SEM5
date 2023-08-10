#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main(){

	// declaring file pointers and variables
	FILE *fa,*fb;
	int ca, i=0, j, k;
	char buffer[100], ch, keywords[10][100] = {"int", "main", "if", "while", "do", "FILE", "char", "float", "continue", "break"};

	// opening files
	fa = fopen("sample3.txt", "r");
	fb = fopen("result3.txt","w+");

	// checking if file opens
	if (fa == NULL){
		printf("Cannot open file \n");
		exit(0); 
	}

	// initializing ca
	ca = getc(fa);
	
	printf("=== Keyword Found in the Document ===\n");

	// going through the document
	while(ca != EOF){

		// skipping non alphanumeric
		if(isalpha(ca) == 0) {
			i=0;
			ca = getc(fa);
			continue;
		}
		
		// creating word
		while(isalpha(ca) != 0){
			buffer[i++] = ca;
			ca = getc(fa);
		}

		// adding null char to end
		buffer[i] = '\0';

		// matching and printing buffer
		for(j = 0; j<10; j++){
			if(strcmp(buffer, keywords[j]) == 0)
			{
				for(k = 0; buffer[k] != '\0'; k++){
					putc(toupper(buffer[k]),fb);
				}
				printf("\n");
			}
			else
			{
				for(k = 0; buffer[k] != '\0'; k++){
					putc(buffer[k],fb);
				}
			}
		}
		ca=getc(fa);
	}

	// closing files
	fclose(fa);
	fclose(fb);
	return 0;
}









/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char array[6][10] = {"if","else","auto","else if","break","continue"};
	FILE *fa,*fb;
	fa = fopen("sample3.txt","r");
	fb = fopen("result3.txt","w");

	if(fa==NULL)
	{
		printf("Cant open your file ");
		exit(0);
	}
	char buffer[100];
	char ca;
	int i=0;
	ca = getc(fa);
	while (ca!=EOF)
	{
		while(ca!=' ')
		{
			buffer[i]=ca;
			i++;
		}
		if (strcmp(buffer,array[i])==0)
		{
			putc(toupper(buffer),fb);
		}
		else
			putc(buffer,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);	
	return 0;
}
*/