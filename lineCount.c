#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


/* count lines in input */
int main()
{

	int c, n1;

	n1 = 0;
	while ( (c = getchar()) != EOF) {
		if (c == '\n')
			++n1;
		printf("%d\n", n1);
	}

}