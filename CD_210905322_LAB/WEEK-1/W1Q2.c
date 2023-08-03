#include <stdio.h>
#include <stdlib.h> 
int main()
{
	FILE *fa, *fb;
	fa = fopen("sample.txt", "r");
	fb = fopen("copied.txt", "w+");

	int c;
	int pos;

	// Moving pointer to end
    fseek(fa, 0, SEEK_END);

    // Getting position of last pos
    pos = ftell(fa);

    // printing size of file
    printf("Size of File : %d\n", pos);

    while(pos >= 0){
    	c = getc(fa);
    	putc(c, fb);

    	// Moving pointer to a one position back
    	pos--;
    	fseek(fa, pos, SEEK_SET);
    }

    // Moving pointer to end
    fseek(fa, 0, SEEK_END);

    
    fclose(fa);
    fclose(fb);
    return 0;
}