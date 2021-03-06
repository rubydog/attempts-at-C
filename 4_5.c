#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */
#define ALPHA '1'
int getop(char []);
void push(double);
double pop(void);
void printtop();
void duplicate();
void swap();
void clear();
/* reverse Polish calculator */ 
main()
{
	int type;
	double op2;
        char s[MAXOP];
	while ((type = getop(s)) != EOF) { switch (type) {
		printf("%s", s);
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
		case '/':
			op2 = pop();
			if (op2 != 0.0) 
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) 
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
        case 'p':
                printtop();
                break;
        case 'd':
                duplicate();
                break;
        case 'c':
                clear();
                break;
        case 's':
                swap();
                break;
		case 'sin':
				push(sin(pop()));
				break;
		case 'pow':
				push(pow(pop()**pop());
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


#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */ 
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */ 
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */ 
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n"); return 0.0;
	}
}

int getch(void); 
void ungetch(int);
/* getop: get next character or numeric operand */ 
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t') 
		;
	s[1] = '\0';
	
	if (!isalpha(c) && !isdigit(c) && c != '.')
		return c; /* not a number */ 
    i = 0;
	if (isalpha(c))
		while (isalpha(s[++i] = c = getch()))
			;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch())) ;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
	
void ungetch(int c) /* push character back on input */ 
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void duplicate() {
  int i = 0;
  double op2;
  op2 = pop();
  pop();
  push(op2);
  push(op2);
}

void swap() {
  double op1, op2;
  op2 = pop();
  op1 = pop();
  push(op2);
  push(op1);
}

void clear() {
  sp = 0;
}

void printtop() {
  double op2;
  op2 = pop();
  push(op2);
  printf("\t%.8g\n", pop());
}
