#include <stdio.h>

/* print Celsius-Fahrenheit table*/

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


int main()
{

	
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	/* print heading */
	printf("Celsius-Fahrenheit Table\n\n");

	celsius = lower;
	while ( celsius <= upper ) {
		fahr = (9.0 / 5.0) * (celsius + 32.0);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}


}