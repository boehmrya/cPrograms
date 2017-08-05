#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, .... , 300 */

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