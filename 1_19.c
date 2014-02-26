/*
 * Exercise 1.19
 *
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 *
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[]);

main()
{
    char line[MAXLINE];

    while ((getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s",line);
    }
    return 0;
}

void reverse(char s[])
{
    int length;
    int c, i, j;

    for (length = 0; s[length] != '\0'; ++length)
        ; 
    char r[length];

    for(i = length-2, j = 0; i >=0; --i, ++j) {
        r[j] = s[i];
    }

    r[length-1] = s[length-1];
    r[length] = '\0';

    copy(s,r);
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}