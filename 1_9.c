#include <stdio.h>

main() {
	int character, character_buffer;
	character_buffer = -1;
	
	while((character = getchar()) != EOF) {
		if (character_buffer == ' ' && character == ' ')
			;
		else {
			putchar(character);
			character_buffer = character;
		}
	}
	
}