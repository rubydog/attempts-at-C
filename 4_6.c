#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */
#define MAXCHAR 1000
#define NUMBER '0' /* signal that a number was found */
#define ALPHA '1'
int getop(char []);
void push(double);
double pop(void);
int is_equal(char s[], int j);
char variable_list[MAXCHAR];
double variable_value[MAXCHAR];
int variable_size[MAXCHAR];
int total_variable_size = 0;
int variable_count = 0;
/* reverse Polish calculator */ 
int main()
{
	int type, i, j;
	double op2;
        char s[MAXOP];
	int found = 0;
	while ((type = getop(s)) != EOF) { switch (type) {
		/* case ALPHA: */
			/* for (i = 0; i < 1000; i+=10) { */
			/* 	for(int j = 0; s[j] != '\0'; j++) { */
			/* 		if (variable_list[i+j] = s[j] { */
			/* 			; */
			/* 		} else { */
			/* 			break; */
			/* 		} */
			/* 	} */


			/* } */
			/* for (i = 0; s[i] != '\0'; i++) */
			/* 	variable_list[(variable_index*10)+i] = s[i]; */
			/* variable_list[(variable_index*10)+i] = '\0'; */
		case ALPHA:
			for (j = i = 0; i < MAXCHAR && variable_size[j] != 0; i += variable_size[j++]) {
				found = is_equal(s, i);
				if (found)
					break;
			}

			if (found)
			{
				push(variable_value[j]);
			} else {
				for (i = 0; s[i] != '\0'; i++)
					variable_list[total_variable_size++] = s[i];
				variable_list[total_variable_size++] = '\0';
				variable_size[variable_count] = i;
			}
			printf("list: %c\n", variable_list[i]);
			/* for (i = 0; i < 51; i++) { */
			/* 	if (variable_list[i] == s[0]) { */
			/* 		push(variable_value[i]); */
			/* 		break; */
			/* 	} */
			/* } */
			/* if (i >= 51) */
			/* { */
			/* 	variable_list[variable_index] = s[0]; */
			/* } */

			printf("size: %d\n", variable_size);
			printf("value: %f\n", variable_value);
			break;
		case '=':
			op2 = pop();
			variable_value[variable_count++] = op2;
			push(op2);
			break;
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
	if (isalpha(c)) {
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return ALPHA;
	}
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

int is_equal(char s[], int j)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != variable_list[j + i])
			return 0;
	}

	return 1;
}

