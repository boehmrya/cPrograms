#include <stdio.h>

/* TO COMPILE: clang binarySearch.c -o binarySearch */
/* TO RUN: ./binarySearch */


int binsearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
    	mid = (low + high) / 2;
    	if (x < v[mid])
    		high = mid - 1;
    	else if (x > v[mid])
    		low = mid + 1;
    	else
    		return mid;
    }
    return -1;
}


int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
    	mid = (low + high) / 2;
    	if (x < v[mid])
    		high = mid - 1;
    	else
    		low = mid + 1;
    }
    if (v[mid] == x) { // low and high will be equal, only have to test one
    	return mid;
    }
    return -1;
}



int main() {
	int v[] = {1, 3, 4, 7, 10, 14, 20, 22};

    printf("binary search 1: %d\n", binsearch1(20, v, 8));
    printf("binary search 2: %d\n", binsearch2(20, v, 8));

    return 0;
}



