#include <stdio.h>
#include <string.h>

//hi there fantastic beast of burden

// function to count the number of words in a string
int countWords(char wordString[]) {
	int len, i, start, count;
	len = strlen(wordString);
	i = 0;
	while (i < len) {
		if (wordString[i] == ' ' || wordString[i] == '\t' || wordString[i] == '\n') {
			count++;
		}
		i++;
	}
	return count;
}

// function to count the maximum-length word in a string
int maxWordLen(char wordString[]) {
	int max, count, i, len;
	len = strlen(wordString);
	max = 0;
	i = 0;
	while (i < len) {
		if (wordString[i] == ' ' || wordString[i] == '\t' || wordString[i] == '\n') {
			if (count > max) {
				max = count;
			}
			count = 0;
		}
		else {
			count++;
		}
		i++;
	}
	return max;
}

/* plot word length */
int main() {
	int i, j, count, wordLengths, strlength;
	char str[512];
	char bar[512];
	 
	// get string and initialize array of word lengths to 0
    fgets(str, 512, stdin);
    wordLengths = maxWordLen(str) + 1;
	int wordLenArr[wordLengths];
	for (i = 0; i < wordLengths; i++) {
		wordLenArr[i] = 0;
	}

    // count word length frequency and store in array
    strlength = strlen(str);
	i = 0;
	while (i < strlength)	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
			wordLenArr[count]++;
			count = 0;
		}
		else {
			count++;
		}
		i++;
	}

	// print histogram of word length frequencies
	for (i = 0; i < wordLengths; i++) {
		printf("%d: ", i);
		for (j = 0; j < wordLenArr[i]; j++) {
			bar[j] = '-';
		}
		printf("%s\n", bar);

		// reset bar char array to empty characters
		for (j = 0; j < wordLenArr[i]; j++) {
			bar[j] = ' ';
		}
	}

}