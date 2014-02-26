#include <stdio.h>
#define MAXLINE 1000
	
gettext(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];
	
	while((len = gettext(line, MAXLINE)) > 0)
		printf("%d %s", len, line);
}

int gettext(char s[], int limit)
{
	int character, i;
	for(i = 0; i < limit - 1 && (character = getchar()) != EOF && character != '\n'; i++)
		s[i] = character;
	if (character == '\n') {
		i++;
	}
	
	s[i] = '\0';
	return i;
}