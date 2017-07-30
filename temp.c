#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, .... , 300 */

/* TO COMPILE: clang program.c -o program*/
/* TO RUN: ./program */


int main()
{

	/* print Fahrenheit-Celsius table*/
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	/* print heading */
	printf("Fahrenheit-Celsius Table\n\n");

	fahr = lower;
	while ( fahr <= upper ) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

}