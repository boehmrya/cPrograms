#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* 
TO COMPILE: clang itoa.c -o itoa
TO RUN: ./itoa
*/

#define MAXLINE 1000


/* reverse string s in place */
void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* convert integer n to string s */
void itoa(int n, char s[]) {
	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}


/* convert integer n to string s */
void itoa2(int n, char s[], int min) {
	int i, k, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	if (strlen(s) < min) {
		while (i < min) {
			s[i++] = ' ';
		}
	}
	s[i] = '\0';
	reverse(s);
}


/* convert integer n to string s */
void itob(int n, char s[], int b) {
	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		if ((n % b + '0') > 57) {
			s[i++] = n % b + '0' + 7;
		}
		else {
			s[i++] = n % b + '0';
		}
	} while ((n /= b) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}


/* read in file and execute the fcfs algorithm */
int main( int argc, char *argv[] ) {
	char s1[MAXLINE];
	char s2[MAXLINE];
	char s3[MAXLINE];

	itoa(123, s1);

	itoa2(123, s2, 6);

	itob(123678, s3, 2);

	printf("string s1 using itoa from n: %s\n", s1);
	printf("string s2 using itoa2 from n with min 6: %s\n", s2);
	printf("string s3 using itob from n: %s\n", s3);
	
	return 0;
}

