#include <stdio.h>

/* Yay! No missing semicolon error.. calls for beer!! \m/ */

main()
{
	float farenheit, celcius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	celcius = lower;
	
	printf("%s\t%s\n", "Celcius", "Farenheit");
	
	while(celcius <= upper) {
		farenheit = (9.0/5.0) * (celcius + 32.0);
		printf("%2.0f\t%6.1f\n", celcius, farenheit);
		celcius = celcius + step;
	}
}