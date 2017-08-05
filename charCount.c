#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


int main()
{

	long nc;

	nc = 0;
	while (getchar() != EOF) {
		++nc;
		printf("%ld\n", nc);
	}

}