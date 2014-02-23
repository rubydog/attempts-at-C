#include <stdio.h>

main() 
{
	int character;
	
 	while((character = getchar()) != EOF)
 		if (character == ' ' || '\t')
			character = '\n';
 
	printf("%d", character);
	
}