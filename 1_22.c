#include <stdio.h>
#define MAXLINE 1000
#define LINELENGTH 20

main() {
	int character, i;
	char line[MAXLINE];
	
	for(i = 0; i < MAXLINE - 1 && (character = getchar()) != EOF; i++) {
		putchar(character);
		if ((i != 0) && ((i % LINELENGTH) == 0)) {
			if (character != ' ' || character != '\t' || character != '\n')
				printf("%s", "\n");
		}
	}
}