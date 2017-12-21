#include <stdio.h>

/* TO COMPILE: clang lower.c -o lower */
/* TO RUN: ./lower */


int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}



int main() {
    printf("lower: %d\n", lower(67));

    return 0;
}