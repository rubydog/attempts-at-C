/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to 
 the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a 
 symbolic parameter? */

#include <stdio.h>
#define TABSTOP 4
#define MAXLINE 1000

main() {
	char line[1000];
	int character, i, spaces;
	
	for(i=0; i < MAXLINE - 1 && (character = getchar()) != EOF; i++) {
		if (character == '\t') {
			  spaces = TABSTOP - (i % TABSTOP);
		   	  while (spaces > 0) {
		  		  line[i] = ' ';
			   	  i++;
				  spaces--;
			  }
			  i--;
		}
		else
			line[i] = character;
	}
		
	line[i] = '\0';
	printf("%s", line);
}

