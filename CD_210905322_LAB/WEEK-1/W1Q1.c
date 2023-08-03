#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fptr1,*fptr2;
	char name[100],c;
	int count=0,line=0;
	printf("Enter name of the file : ");
	scanf("%s",name);
	fptr1 = fopen(name,"r");
	if (fptr1==NULL)
	{
		printf("No such file");
		exit(0);
	}
	/*printf("Enter name of the file : ");
	scanf("%s",name);
	fptr2 = fopen(filename,"w+");*/
	c = fgetc(fptr1);
	while (c!=EOF)
	{
		if(c=='\n')
			line=line+1;
		count=count+1;
		c = fgetc(fptr1);
	}
	fclose(fptr1);
	if(count>0)
		line++;
	//fclose(ptr2);
	printf("Number of lines is %d \nNumber of characters are %d",line,count);
	return 0;
}