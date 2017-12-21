#include <stdio.h>

/* TO COMPILE: clang bits.c -o bits */
/* TO RUN: ./bits */


unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & (~(~0 << n))) << (p + 1 - n));
}


unsigned invert(unsigned x, int p, int n) {
    return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | (((~(x >> (p + 1 - n))) & (~(~0 << n))) << (p + 1 - n));
}

unsigned rightrot(unsigned x, int n) {
    return x >> n;
}


int main() {
    printf("answer for getbits: %d\n", getbits(91, 4, 3));
    printf("answer for setbits: %d\n", setbits(91, 4, 3, 107));
    printf("answer for invert: %d\n", invert(91, 4, 3));
    printf("answer for rightrot: %d\n", rightrot(91, 3));

    return 0;
}

