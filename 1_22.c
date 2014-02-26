#include <stdio.h>
#define LINELENGTH 20

main() {
	int character, i;
	
	for(i = 1; (character = getchar()) != EOF; i++) {
		putchar(character);
		if ((i % LINELENGTH) == 0) {
			if (character != ' ' || character != '\t' || character != '\n')
				printf("%s", "\n");
		}
	}
}