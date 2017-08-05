#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


/* count lines in input */
int main()
{

	int c, count, blankCount;

	count = 0;
	while ( (c = getchar()) != EOF) {
		blankCount = 0;
		if (c == ' ') {
			blankCount = 1;
			while ( (c = getchar()) == ' ' ) {
				++blankCount;
			}
			putchar(' ');
			putchar(c);
		}
		else {
			putchar(c);
		}
		count = count + blankCount;	
	}

}