#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


int main()
{

	int c;

	while ( (c = getchar()) != EOF) {
		putchar(c);
		c = getchar();
	}

}