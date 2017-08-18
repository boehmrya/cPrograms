#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */

/* count lines, words, and characters in input */
int main()
{

	int c;

	while ( (c = getchar()) != EOF) {
		if ( c == ' ' || c == '\n' || c == '\t' )
			putchar('\n');
		else {
			putchar(c);
		}
	}

}