#include <stdio.h>
#define MAXCHAR 1000

main() {
	int character, i, j=0, flag = 0, print = 1;
	char string[MAXCHAR];
	
	for(i=0; i < MAXCHAR - 1 && (character = getchar()) != EOF; i++) {
		if (print) {
			string[i] = character;
			if (character == '*' && string[i-1] == '/') {
				print = 0;
				i -= 3;
			}
		}
		else if (!print) {
			if (character == '*') {
				flag = 1;
			}
			//comment ends
			else if (flag && character == '/'){
				print = 1;
				flag = 0;
				i -= j;
			}
			else if (flag){
				flag = 0;
			}
			j++;
		}
	}
	
	if (i < (MAXCHAR - 1))
		string[i++] = '\0';
	else
		string[MAXCHAR - 1] = '\0';
	printf("\n%s\n", string);
}