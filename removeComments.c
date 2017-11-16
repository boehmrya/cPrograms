#include <stdio.h>

/* TO COMPILE: clang enTab.c -o enTab */
/* TO RUN: ./enTab */

//hello   hey what are you    doing sir

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
void enTab(char to[], char from[]) {
	int i, j, k, spaceCount, numTabs, len;

	len = lineLength(from); // length of the line
	i = 0, 
	j = 0;
	spaceCount = 0;
	numTabs = 0;

	while (i < len) {
		if (from[i] == ' ') {
			spaceCount += 1;
			i++;
		}
		else {
			if ( spaceCount > 1 ) {
				numTabs = spaceCount / 2;
				k = 0;
				while ( k < numTabs ) {
					to[j] = '\t';
					j++;
					k++;
				}
				if ( spaceCount % 2 == 1 ) {
					to[j] = ' ';
					j++;
				}
				// add next letter
				to[j] = from[i];
				j++;
				i++;

				// reset space and tab trackers
				spaceCount = 0;
				numTabs = 0;
			}
			else if ( spaceCount == 1 ) {
				// add space
				to[j] = ' ';
				j++;

				// add next letter
				to[j] = from[i];
				j++;
				i++;
				spaceCount = 0;
			}
			else {
				to[j] = from[i];
				j++;
				i++;
			}
		}	
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
	char enTabLine[MAXLINE]; /* reversed line */

	while ((len = getLine(line, MAXLINE)) > 0) {
		enTab(enTabLine, line);
		// check if only newline in cleaned line
		printf("enTab line: %s\n", enTabLine);
	}
}

