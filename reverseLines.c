#include <stdio.h>

/* TO COMPILE: clang reverseLines.c -o reverseLines */
/* TO RUN: ./reverseLines */

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
void reverse(char to[], char from[]) {
	int i, j, len;

	len = lineLength(from); // length of the line
	i = len - 1; // counter
	j = 0;

	while (i >= 0) {
		if (from[i] == '\n') {
			i--;
		}
		else {
			to[j] = from[i];
			i--;
			j++;
		}	
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
	char reversedLine[MAXLINE]; /* reversed line */

	while ((len = getLine(line, MAXLINE)) > 0) {
		reverse(reversedLine, line);
		// check if only newline in cleaned line
		printf("reversed line: %s\n", reversedLine);
	}
}

