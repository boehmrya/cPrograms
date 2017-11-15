#include <stdio.h>

/* TO COMPILE: clang deTab.c -o deTab */
/* TO RUN: ./deTab */

#define MAXLINE 1000


/* getline: read a line into s, return length */
int lineLength( char s[] ) {
	int i = 0;
	while ( s[i] != '\0') {
		i++;
	}
	return i;
}


/* reverse the string from, and copy it into string to. */
void deTab(char to[], char from[]) {
	int i, j, len;

	len = lineLength(from); // length of the line
	i = 0, j = 0; // counter

	while (i < len) {
		if (from[i] == '\t') {
			to[j] = ' ';
			to[j + 1] = ' ';
			j += 2;
		}
		else {
			to[j] = from[i];
			j++;
		}	
		i++;
	}
	to[j] = '\n';
}


/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
	int c, i;

	for (i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); i++ ) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}


/* print longest input line */
int main() {
	int len; 		/* current line length */
	char line[MAXLINE]; 	/* current input line */
	char deTabLine[MAXLINE]; /* reversed line */

	while ((len = getLine(line, MAXLINE)) > 0) {
		deTab(deTabLine, line);
		// check if only newline in cleaned line
		printf("deTab line: %s\n", deTabLine);
	}
}

