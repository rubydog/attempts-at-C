#include <stdio.h>

main() {
	int character, i, j;
	int length[100];
	
	for(i = 0; i < 100; i++) 
		length[i] = 0;

	i = 0;
	while((character = getchar()) != EOF) {
		if (character == ' ' || character == '\t' || character == '\n')
			i++;
		else
			length[i]++;
			
	}
	
	for(j = 0; j <= i; j++) {
		while(length[j] > 0) {
			printf("%s", "[]");
			--length[j];
		}
		printf("%s", "\n");
	}
}