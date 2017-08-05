#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, .... , 300 */

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


#define LOWER 0
#define UPPER 300
#define STEP 20


int main()
{

	/* print Fahrenheit-Celsius table*/
	int fahr;

	/* print heading */
	printf("Fahrenheit-Celsius Table\n\n");

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));

}