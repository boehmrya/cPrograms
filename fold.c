#include <stdio.h>

/* TO COMPILE: clang fold.c -o fold */
/* TO RUN: ./fold */

//hello hey what are you doing sir? Are you having a good day?

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
void fold(char to[], char from[], int n) {
	// declare vars
	int i, j, len, makeBreak;

	// initialize vars
	len = lineLength(from); // length of the line
	i = 0; // counter for total characters in array to transfer
	j = 0, // counter up to the line break value (n)
	makeBreak = 0; // lets program know to make a line break at the next space or tab

	// transfer array
	while (i < len) {
		// set makeBreak
		if ( j == n ) {
			makeBreak = 1;
		}

		// determine if we need a line break
		if ((from[i] == ' ' || from[i] == '\t') && (makeBreak == 1)) {
			to[i] = '\n';
			j = 0;
			makeBreak = 0;
		}
		else {
			to[i] = from[i];
		}
		j++;
		i++;	
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
	int len; 				/* current line length */
	int n = 25;				/* fold line after every n characters */
	char line[MAXLINE]; 	/* current input line */
	char foldLine[MAXLINE]; /* reversed line */

	while ((len = getLine(line, MAXLINE)) > 0) {
		fold(foldLine, line, n);
		// check if only newline in cleaned line
		printf("%s", foldLine);
	}
}

