#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, .... , 300 */

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