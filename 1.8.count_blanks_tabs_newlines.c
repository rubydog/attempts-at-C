#include <stdio.h>

main()
 {
	int character, tab_count, blank_count, newline_count;
	
	tab_count = 0;
	blank_count = 0;
	newline_count = 0;
	
	while((character = getchar()) != EOF)
		if (character == '\n')
			++newline_count;
		else if (character == '\t')
			++tab_count;
		else if (character == '\0')
			++blank_count;
	printf("\n%s\t%d\n%s\t%9d\n%s\t%9d\n", "Newlines", newline_count, "Tabs", tab_count, "Blanks", blank_count);
}