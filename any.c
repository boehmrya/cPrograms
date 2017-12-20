#include <stdio.h>

/* TO COMPILE: clang any.c -o any */
/* TO RUN: ./any */


int any( char s1[], char s2[] ) {
    int i, j;

    i = 0;
    while (s2[i] != '\0') {
        j = 0;
        while (s1[j] != '\0') {
            if (s1[j] == s2[i]) {
                return j;
            }
            j++;
        }
        i++;
    }
    return -1;
}

int main() {
    char s1[] = "bintip";
    char s2[] = "hello";
    int loc = any(s1, s2);
    printf("first location in s1 of character in s2: %d\n", loc);
    return 0;
}

