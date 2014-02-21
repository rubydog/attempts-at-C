# include <stdio.h>

/* Yay! No missing semicolon error.. calls for beer!! \m/ */

main()
{
	float farenheit, celcius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	farenheit = lower;
	
	printf("%2s\t%s", "Farenheit", "Celcius\n");
	
	while(farenheit <= upper) {
		celcius = (5.0/9.0) * (farenheit - 32.0);
		printf("%2.0f\t%15.1f\n", farenheit, celcius);
		farenheit = farenheit + step;
	}
}