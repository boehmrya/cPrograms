#include <stdio.h>

/* TO COMPILE: clang squeeze.c -o squeeze */
/* TO RUN: ./squeeze */


void squeeze( char s1[], char s2[] ) {
    int i, j, k, index, match;

    i = 0;
    match = 0;
    while (s1[i] != '\0') {
        j = 0;
        match = 0;
        while (s2[j] != '\0') {
            if (s1[j] == s2[i]) {
                match = 1;
                index = j;
                break;
            }
            j++;
        }
        if (match == 1) {
            j = 0;
            k = 0;

            while (s1[j] != '\0') {
                if (k != index) {
                    s1[j] = s1[k];
                    j++;
                    k++;
                }
                else {
                    k++;
                }
            }
            s1[j] = '\0';
        }
        i++;
    }
    s1[i] = '\0';
}

int main() {
    char s1[] = "hilltop";
    char s2[] = "hello";
    squeeze(s1, s2);
    printf("s1 modified: %s\n", s1);
	
    return 0;
}

