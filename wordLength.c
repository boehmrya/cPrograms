#include <stdio.h>


int countWords(char wordString[]) {
	int len, i, start, count;
	len = strlen(wordString);
	i = 0;
	while (i < len) {
		if (wordString[i] == ' ' || wordString[i] == '\t' || wordString[i] == '\n') {
			count++;
		}
	}
	return count;
}

/* plot word length */
int main() {
	int i, count, spaces;
	char wordline[512];

	// get first part of command
    fgets(wordline, 512, stdin);
    wordlinelen = strlen(wordline);

	i = 0;
	while (i < wordlinelen)	{

	}	

}