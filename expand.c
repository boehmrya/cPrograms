#include <stdio.h>
#include <ctype.h>

/* 
TO COMPILE: clang expand.c -o expand
TO RUN: ./expand
*/

#define MAXLINE 1000


/* length of string */
int lineLength( char s[] ) {
	int i = 0;
	while ( s[i] != '\0') {
		i++;
	}
	return i;
}


/* expand abbreviated strings */
void expand(char s1[], char s2[]) {
	int i, j, k, c, istart, iend, len, range;
	char cval;
	i = 0;
	j = 0;
	len = lineLength(s1);
	while (i < len) {
		if (s1[i] == '-') {
			i++;
			if (i == 0) {
				// ignore opening dash
				continue;
			}
			else {
				// we are in a range that needs to be expanded
				range = 1;
			}
		}
		else {
			c = tolower(s1[i]);
			if (range == 0) {
				istart = c;
			}
			else {
				iend = c;
				range = 0;
				k = istart;
				while (k <= iend) {
					cval = (char) k;
					s2[j] = cval;
					k++;
					j++;
				}
			}
			i++;
		}
	}
}


/* read in file and execute the fcfs algorithm */
int main( int argc, char *argv[] ) {
	char line1[] = {'a', '-', 'z'};
	char line2[] = {'a', '-', 'z', '0', '-', '9'};
	char newLine1[MAXLINE]; // line without comments
	char newLine2[MAXLINE]; // line without comments
	int i, len;

   	expand(line2, newLine2);

   	// print the expanded line
   	i = 0;
   	len = lineLength(newLine2);
   	while (i < len) {
   		printf("%c\n", newLine2[i]);
   		i++;
   	}	
	
	return 0;
}

