#include <stdio.h>
#include <ctype.h>

/* TO COMPILE: clang hexToInt.c -o hexToInt */
/* TO RUN: ./hexToInt */


/* getline: read a line into s, return length */
int lineLength( char s[] ) {
    int i = 0;
    while ( s[i] != '\0') {
        i++;
    }
    return i;
}


int atoi( char s[] ) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}


int htoi( char s[] ) {
    int i, n, c, dig, multiple;

    i = lineLength(s) - 1;
    dig = 0;
    multiple = 1;
    n = 0;
    c = 0;

    while (i >= 0) {
        // check if first two digits are 0x, skip if so
        if (i == 1 && ((tolower(s[i]) == 'x') && (s[i-1] == '0'))) {
            break;
        }
        else { // otherwise, convert digits to an int
            c = tolower(s[i]);
            if ( c >= 'a' && c <= 'f') {
                dig = c - 97 + 10;
            }
            else {
                dig = c - 48;
            }

            // update the integer value
            n = n + (dig * multiple);

            // update vars
            i--;
            multiple = multiple * 16;
            dig = 0;
        }
    }
    return n;
}

int main() {
    char s[] = "f";
    char s2[] = "0x55";
    printf("the s value: %d\n", htoi(s));
    printf("the s2 value: %d\n", htoi(s2));
	
    return 0;
}