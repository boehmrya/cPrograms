#include <stdio.h>

/* TO COMPILE: clang removeBlanks.c -o removeBlanks */
/* TO RUN: ./removeBlanks */


#define MAXLINE 1000


/* getline: read a line into s, return length */
int lineLength( char s[] ) {
	int i = 0;
	while ( s[i] != '\0') {
		i++;
	}
	return i;
}


/* 
copy: copy 'from' into 'to'; assume to is big enough
remove trailing tabs and spaces
assume to has enough space
*/
void removeTrail(char to[], char from[]) {
	int i, len, trail;

	len = lineLength(from); // length of the line
	trail = 1; // indicates we are at the end of the line
	i = len; // counter

	printf("from: %s\n", from);
	while (i >= 0) {
		if (trail == 1) {
			// don't copy blanks and tabs to new line if at the trail of the line
			if ((from[i] != ' ') && (from[i] != '\t')) {
				trail = 0;
				continue;
			}
		}
		to[i] = from[i];
		i--;
	}
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
	char cleanLine[MAXLINE]; /* line without trailing blanks and spaces */

	while ((len = getLine(line, MAXLINE)) > 0) {
		removeTrail(cleanLine, line);
		// check if only newline in cleaned line
		if ( lineLength(cleanLine) == 1 && cleanLine[0] == '\n' ) {
			continue;
		}
		else {
			printf("cleaned line: %s\n", cleanLine);
		}
	}
}

