#include <stdio.h>

main() {
	int character;

	while((character = getchar()) != EOF) {
		if (character == '\t')
			character = "\\t";
		if (character == '\b')
			character = "\\b";
		if (character == '\\')
 			character = "\\\\";
		putchar(character);
	}
}