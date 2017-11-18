#include <stdio.h>

/* 
TO COMPILE: clang removeComments.c -o removeComments
TO RUN: ./removeComments sample.c newSample.c 
*/

#define MAXLINE 1000


/* getline: read a line into s, return length */
int lineLength( char s[] ) {
	int i = 0;
	while ( s[i] != '\0') {
		i++;
	}
	return i;
}


/* returns first non-white-space index */
int nonWhiteSpaceIndex( char s[] ) {
	int i = 0;
	while (( s[i] != ' ') && ( s[i] != '\t')) {
		i++;
	}
	return i;
}


/* reverse the string from, and copy it into string to. */
void removeComments(char to[], char from[]) {
	int i, len;
	i = nonWhiteSpaceIndex(from);
	len = lineLength(from);
	while (i < len) {
		// if at a comment at the end of a line, just exit
		if ((from[i] == '/') && (from[i + 1] == '/')) {
			return;
		}
		else if ((from[i] == '/') && (from[i + 1] == '*')) {
			return;
		}
		else {
			to[i] = from[i];
		}
		i++;
	}
}


/* checks if the entire line is a comment */
int lineComment( char line[] ) {
	int i = nonWhiteSpaceIndex(line);
	if ((line[i] == '/') && ((line[i + 1] == '*') || (line[i + 1] == '/'))) {
		return 1;
	}
	else {
		return 0;
	}
}


/* checks if the entire line is a comment */
int multiLineComment( char line[] ) {
	int len = lineLength(line);
	int endIndex = len - 1;
	int i = nonWhiteSpaceIndex(line);
	if ( len == 2 ) {
		if ((line[i] == '/') && (line[i + 1] == '*')) {
			return 1;
		}
		else if ((line[i] == '*') && (line[i + 1] == '/')) {
			return 1;
		}
	}
	else {
		if ((line[i] == '/') && (line[i + 1] == '*')) {
			if ((line[endIndex - 1] != '*') || (line[endIndex] != '/')) {
				return 1;
			}
		}
	}
	return 0;
}


/* checks if we have reached the end of a multi line comment */
int endMultiLineComment( char line[] ) {
	int len = lineLength(line);
	int endIndex = len - 1;
	int i = nonWhiteSpaceIndex(line);
	if ( len == 2 ) {
		if ((line[i] == '*') && (line[i + 1] == '/')) {
			return 1;
		}
	}
	else if ( len > 2 ) {
		if ((line[i] != '/') || (line[i + 1] != '*')) {
			if ((line[endIndex - 1] == '*') && (line[endIndex] == '/')) {
				return 1;
			}
		}
	}
	return 0;
}


/* read in file and execute the fcfs algorithm */
int main( int argc, char *argv[] ) {
	FILE *infile;
	FILE *outfile;
	char *outfilename;
	char *infilename;
	char line[MAXLINE]; // line with comments
	char newLine[MAXLINE]; // line without comments
	int multiComment = 0; // indicates if the whole line is a comment

	if(argc == 3) {
		// get filenames from command line arguments
		infilename = argv[1];
		outfilename = argv[2];

		// open input and output files
    	infile = fopen(infilename, "r");
    	outfile = fopen(outfilename, "w+");

    	// check and make sure input file exists
    	if(infile == NULL) {
      		perror("Error opening input file");
      		return(-1);
   		}

   		// get lines from input file
   		// write to output file without comments
   		while (fgets (line, MAXLINE, infile) != NULL) {
   			if (multiLineComment(line) == 1) {
   				multiComment = 1;
   			}
   			else if (lineComment(line) == 1) {
   				continue;
   			}
   			else {
   				if (endMultiLineComment(line) == 1) {
   					multiComment = 0;
   				}
   				else if (multiComment == 1) {
   					continue;
   				}
   				else {
   					// remove comments and write line to output file
   					removeComments(newLine, line);
   					fputs(newLine, outfile);
   				}
   			}
   		}
   		// close both files
   		fclose(infile);
   		fclose(outfile);
   }
	// errors for incorrect arguments
	else if( argc > 3 ) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("Two argument expected.\n");
	}
	return 0;
}

