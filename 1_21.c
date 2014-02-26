/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to
   achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would 
   suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define TABSTOP 10
#define TABSPACE 5
#define MAXLINE 1000

main() {
	char line[MAXLINE];
	int character, i, blanks = 0, tabs, spaces, i_position;
	
	for(i = 0; i <= MAXLINE - 1 && ((character = getchar()) != EOF); i++) {
		if (character == ' ') {
			blanks++;
		}
		else if (character == '\t') {
			blanks += TABSPACE;
		}
		else {
			if (blanks > 0) {
				int blocks_remaining = (i % TABSTOP);
				i -= blanks;
				if (blanks > blocks_remaining)
					blanks -= blocks_remaining;
				tabs   = blanks / TABSPACE;
				spaces = blanks % TABSPACE;
				while (tabs > 0) {
					line[i] = '\t';
					i++;
					tabs--;
				}
				while (spaces > 0) {
 					line[i] = ' ';
					i++;
					spaces--;
				}
				blanks = 0;
			}
			line[i] = character;
		}				
	}
	
	line[i] = '\0';
	printf("%s", line);
}