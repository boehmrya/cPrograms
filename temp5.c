#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, .... , 300 */

/* TO COMPILE: clang temp5.c -o temp5 */
/* TO RUN: ./program */


int FahrToCelc( int fahr ) {
	int celc = (5.0/9.0) * (fahr-32);
	return celc;
}

void tempTable() {
	/* print Fahrenheit-Celsius table*/
	int fahr;

	/* print heading */
	printf("Fahrenheit-Celsius Table\n\n");

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}


int main() {
	tempTable();
	int fahr = 300;
	int celc = FahrToCelc( fahr );
	printf("Fahr: %d, Celc: %d\n", fahr, celc);
}