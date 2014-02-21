# include <stdio.h>

main() 
{
	int c;
	c = getchar();
	printf("%d", getchar() != EOF);
}