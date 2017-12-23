#include <ctype.h>
#include <stdio.h>

/* 
TO COMPILE: clang atof.c -o atof
TO RUN: ./atof
*/

#define MAXLINE 100


/* getline: get line into s, return length */
int getline2(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}


/* atof: convert string s to double */
double atof(char s[]) {
	double val, power, finalVal;
	int i, sign, exSign, isSci, sciEx, preDec;

	isSci = 0;
	for (i = 0; isspace(s[i]); i++) { /* skip white space */
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	exSign = 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		preDec = i; // number of digits before the decimal
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e') {
		isSci = 1;
		i++;
	}
	if (s[i] == '-') {
		exSign = -1;
		i++;
	}
	if (isdigit(s[i])) { // scientific notation exponent
		sciEx = s[i];
	}
	finalVal = sign * val / power;
	// scientific notation computations if necessary
	if (isSci == 0) {
		return finalVal;
	}
	else {
		if (exSign < 0) {
			while (preDec > 0) {
				finalVal /= 10.0;
				preDec -= 1;
			}
			while (sciEx > 0) {
				finalVal /= 10.0;
				sciEx -= 1;
			}
		}
		else {
			while (sciEx > 0) {
				finalVal *= 10.0;
				sciEx -= 1;
			}
		}
	}
	return finalVal;
}


/* rudimentary calculator */
int main() {
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (getline2(line, MAXLINE) > 0) {
		printf("\t%g\n", sum += atof(line));
	}
	return 0;
}

