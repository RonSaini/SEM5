#include <stdio.h>
#include <stdlib.h>

int main(){
	// declaring file pointers and variables
	FILE *fa, *fa_, *fb;
	int ca, ca_;

	// opening files
	fa = fopen("/home/cdlab/Desktop/CD_210905322_LAB/WEEK-2/sample.txt", "r");
	fa_ = fopen("/home/cdlab/Desktop/CD_210905322_LAB/WEEK-2/sample.txt", "r");
	fb = fopen("result.txt", "w+");

	// checking if file oprns
	if (fa == NULL){
		printf("Cannot open file \n");
		exit(0); 
	}

	// going to first position of the file
	ca = getc(fa);

	// going to the second position of the file
	ca_ = getc(fa_);
	ca_ = getc(fa_);

	// going through the document
	while(ca != EOF){
		if(ca == ' ' && ca_ == ' '){ // if more than 2 consecutive blanks are found
			ca = getc(fa);
			ca_ = getc(fa_);
			continue;
		} else if (ca == '\t' && ca_ == '\t') { // if more than 2 consecutive tabs are found
			ca = getc(fa);
			ca_ = getc(fa_);
			continue;
		} else if (ca == '\t' && ca_ != '\t') { // condensing consecutive tabs
			putc(' ', fb);
			ca = getc(fa);
			ca_ = getc(fa_);
		} else { // writing all other characters into the file
			putc(ca, fb);
			ca = getc(fa);
			ca_ = getc(fa_);
		}
	}

	// closing files
	fclose(fa);
	fclose(fa_);
	fclose(fb);
	return 0;
}