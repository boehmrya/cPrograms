#include <stdio.h>
#include <string.h>
#include <ctype.h>

//TEST SENTENCE: hi there fantastic beast of burden


/* plot frequencies of characters */
int main() {
	int i, j, k, c, strlength;
	char bar[512]; // hold strings to print histogram
	char str[512]; // input string
	char alph[512]; // alphabet characters
	int freq[512]; // frequency of alph characters

	// make alphabet string
	strcpy(alph, "abcdefghijklmnopqrstuvwxyz");

	// initialize freq array to zeros
	for ( i = 0; i < 26; i++) {
		freq[i] = 0;
	}

	// get string and initialize array of word lengths to 0
    fgets(str, 512, stdin);

    // count word length frequency and store in array
    strlength = strlen(str);
	i = 0;
	while (i < strlength)	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
			j = ((int) tolower(str[i])) - 97;
			freq[j]++;
		}
		i++;
	}

	// print histogram of word length frequencies
	for (i = 0; i < 26; i++) {
		j = ((int) tolower(alph[i])) - 97;
		printf("%d: ", j);

		for (k = 0; k < freq[i]; k++) {
			bar[k] = '-';
		}
		printf("%s\n", bar);

		// reset bar char array to empty characters
		for (k = 0; k < freq[i]; k++) {
			bar[k] = ' ';
		}
	}

}