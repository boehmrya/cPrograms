#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


/* 
TO COMPILE: clang reversePolish.c -o reversePolish
TO RUN: ./reversePolish
*/


#define MAXOP 100 /* max size of operand or operator */
#define MAXVAL 100 /* maximum depth of val stack */
#define NUMBER '0' /* signal that a number was found */
#define BUFSIZE 100


int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */


/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("error: stack full, can't push %g\n", f);
	}
}


/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* print top value of stack without removing it */
void peek(void) {
	if (sp > 0) {
		printf("top stack value: %g\n", val[sp]);
	}
	else {
		printf("stack empty");
	}
}


/* duplicate the top value of the stack */
void dupTop(double f) {
	if (sp < MAXVAL) {
		double f = val[sp];
		val[sp++] = f;
	}
	else {
		printf("error: stack full, can't duplicate top value %g\n", f);
	}
}


/* duplicate the top value of the stack */
void clear(void) {
	while (sp > 0) {
		val[--sp] = 0.0;
	}
	printf("stack clear");
}


/* swap the top two elements in the stack */
void swapTop(void) {
	if (sp > 0) {
		double f = val[sp - 1];
		val[sp - 1] = val[sp];
		val[sp] = f;
	}
	else {
		printf("empty stack");
	}
}


/* get a (possibly pushed back) character */
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}


/* push character back on input */
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}


/* pushes entire string onto the input */
void ungets(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
		if (bufp >= BUFSIZE) {
			printf("ungets: too many characters\n");
		}
		else {

			buf[bufp++] = s[i];
		}
		i++;
	}
}


/* getop: get next operator or numeric operand */
int getop(char s[]) {
	int i, c;

	
	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.') { /* if not a number */
		if (c != '-') {
			return c;
		} 
		if ((c == '-') && !isdigit(s[++i] = c = getch())) {
			return c;
		}
	}
	if (isdigit(c)) { /* collect integer part */
		while(isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if (c == '.') { /* collect fraction part */
		while(isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}



int main() {
	int type;
	double op2;
	char s[MAXOP];
	int iexp = 0; // number of exp chars
	int isExp = 0; // are we currently on exp chars

	int isin = 0; // number of sin chars
	int isSin = 0; // are we currently on sin chars

	int ipow = 0; // number of pow chars
	int isPow = 0; // are we currently on pow chars

	while ((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '%':
				op2 = pop();
				push( (double) ((int) pop() % (int) op2));
				break;
			case 'e':
				if (isExp == 0) {
					iexp++;
					isExp = 1;
				}
				else {
					printf("out of place char e");
				}
				break;
			case 'x':
				if (isExp == 1) {
					iexp++;
				}
				else {
					printf("out of place char x");
				}
				break;
			case 'p':
				if (isExp == 1) {
					iexp++;
					if (iexp == 3) {
						push(exp(pop()));
						iexp = 0;
						isExp = 0;
					}
				}
				else if (isPow == 0) {
					ipow++;
					isPow = 1;
				}
				break;
			case 's':
				if (isSin == 0) {
					isin++;
					isSin = 1;
				}
				else {
					printf("out of place char s");
				}
				break;
			case 'i':
				if (isSin == 1) {
					isin++;
				}
				else {
					printf("out of place char s");
				}
				break;
			case 'n':
				if (isSin == 1) {
					isin++;
				}
				if (isin == 3) {
					push(sin(pop()));
					isin = 0;
					isSin = 0;
				}
				break;
			case 'o':
				if (isPow == 1) {
					ipow++;
				}
				else {
					printf("out of place char o");
				}
				break;
			case 'w':
				if (isPow == 1) {
					ipow++;
				}
				if (ipow == 3) {
					op2 = pop();
					push(pow(pop(), op2));
					ipow = 0;
					isPow = 0;
				}
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				}
				else {
					printf("error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

