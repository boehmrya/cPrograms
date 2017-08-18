#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


/* count lines in input */
int main()
{

	int c;

	while ( (c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\t');
		}
		else if (c == '\b') {
			putchar('\b');
		}
		else if (c == '\\') {
			putchar('\\');
		}
		else {
			putchar(c);
		}
	}

}