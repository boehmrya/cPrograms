#include <stdio.h>

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */

//hello there you little person

/* plot word length */
int main()
{

	// initialize variables
	int c, i, j, k, count;
	int wordLengths[20];

	for (i = 0; i < 20; ++i)
		wordLengths[i] = 0;

	count = 0;
	while ( (c = getchar()) != EOF) {
		if ( c == ' ' || c == '\n' || c == '\t' ) {
			++wordLengths[count];
			
			count = 0;
		}
		else {
			++count;
		}
	}
	for (j = 0; j < 20; ++j) {
		printf("%d: ", j);
		for (k = 0; k < wordLengths[j]; ++k) {
			printf("-");
		}
		printf("\n");
	}
		

}