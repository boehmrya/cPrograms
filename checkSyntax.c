#include <stdio.h>

/* 
TO COMPILE: clang checkSyntax.c -o checkSyntax
TO RUN: ./checkSyntax sample.c 
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


/* read in file and execute the fcfs algorithm */
int main( int argc, char *argv[] ) {
	// vars for file and lines
	FILE *infile;
	char *infilename;
	char line[MAXLINE];

	// track if symbols are balanced
	// add one if left side, subtract one if right side
	// should end at 0 if everything is balanced
	int parentheses = 0;
	int brackets = 0;
	int braces = 0;
	int singleQuotes = 0;
	int doubleQuotes = 0;
	int i, len, errors;

	if(argc == 2) {
		// get filenames from command line arguments
		infilename = argv[1];
    	infile = fopen(infilename, "r");

    	// check and make sure input file exists
    	if(infile == NULL) {
      		perror("Error opening input file");
      		return(-1);
   		}

   		// get lines from input file and check symbols
   		while (fgets (line, MAXLINE, infile) != NULL) {
   			i = 0;
   			len = lineLength(line);
   			while (i < len) {
   				if (line[i] == '(') {
   					parentheses += 1;
   				}
   				else if (line[i] == ')') {
   					parentheses -= 1;
   				}
   				else if (line[i] == '[') {
   					brackets += 1;
   				}
   				else if (line[i] == ']') {
   					brackets -= 1;
   				}
   				else if (line[i] == '{') {
   					braces += 1;
   				}
   				else if (line[i] == '}') {
   					braces -= 1;
   				}
   				else if (line[i] == '\'') {
   					singleQuotes += 1;
   				}
   				else if (line[i] == '\"') {
   					doubleQuotes += 1;
   				}
   				i++;
   			}	
   		}
   		// close both files
   		fclose(infile);

   		// check if each symbol is balanced
   		// print out any unbalanced symbols
   		errors = 0;
   		if (parentheses != 0) {
   			printf("parentheses unbalanced\n");
   			errors += 1;
   		}
   		if (brackets != 0) {
   			printf("brackets unbalanced\n");
   			errors += 1;
   		}
   		if (braces != 0) {
   			printf("braces unbalanced\n");
   			errors += 1;
   		}
   		if (singleQuotes % 2 != 0) {
   			printf("single quotes unbalanced\n");
   			errors += 1;
   		}
   		if (doubleQuotes % 2 != 0) {
   			printf("single quotes unbalanced\n");
   			errors += 1;
   		}
   		if (errors == 0) {
   			printf("program is perfectly formed\n");
   		}

   }
	// errors for incorrect arguments
	else if( argc > 2 ) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("Two argument expected.\n");
	}
	return 0;
}

