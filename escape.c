#include <stdio.h>

/* 
TO COMPILE: clang escape.c -o escape
TO RUN: ./escape in.txt out.txt 
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


/* reverse the string from, and copy it into string to. */
void escape(char t[], char s[]) {
	int i, j, len;
	i = 0;
	j = 0;
	len = lineLength(s);
	while (j < len) {
		switch (s[i]) {
			case '\n':
				t[i] = '\\';
				t[i + 1] = 'n';
				i += 2;
				break;
			case '\t':
				t[i] = '\\';
				t[i + 1] = 't';
				break;
			default:
				t[i] = s[j];
				i++;
				break;
		}
		j++;
	}
}


/* read in file and execute the fcfs algorithm */
int main( int argc, char *argv[] ) {
	FILE *infile;
	FILE *outfile;
	char *outfilename;
	char *infilename;
	char line[MAXLINE]; // line with comments
	char newLine[MAXLINE]; // line without comments

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
   			escape(newLine, line);
   			fputs(newLine, outfile);
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

