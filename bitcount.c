#include <stdio.h>

/* TO COMPILE: clang bitcount.c -o bitcount */
/* TO RUN: ./bitcount */


int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1) {
    	if (x & 01) {
    		b++;
    	}
    }
    return b;
}


int bitcountFast(unsigned x) {
    int b;

    while (x != 0) {
    	x &= (x - 1);
    	b++;
    }
    return b;
}




int main() {
    printf("bitcount: %d\n", bitcount(91));
    printf("bitcountFast: %d\n", bitcountFast(91));

    return 0;
}

