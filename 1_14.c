#include <stdio.h>

main() {
	int character, i;
	int character_count[255];
	
	for(i = 0; i <= 255; i++)
		character_count[i] = 0;
	
	while((character = getchar()) != EOF)
		++character_count[character - '0'];
	
	for(i = 33; i <= 127; i++) {
		while(character_count[i] > 0) {
			printf("%s", "]");
			--character_count[i];
		}
		printf("%s", "\n");
	}
}