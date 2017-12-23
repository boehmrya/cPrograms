#include <stdio.h>


/* 
TO COMPILE: clang pattern.c -o pattern
TO RUN: ./pattern
*/


#define MAXLINE 1000


int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);


char pattern[] = "ould"; /* pattern to search for */


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


/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k, max;
	max = 0;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = 1, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0') {
			if (i > max) {
				max = i;
			}
		}
	}
	if (max > 0) {
		return max;
	}
	else {
		return -1;
	}
}


/* find all lines matching pattern */
int main() {
	char line[MAXLINE];
	int found = 0;

	while( getline2(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s\n", line);
			found++;
		}
	}
	return found;
}















