#include <stdio.h>

/* Repating same code with for loop.. Lame but important..  */
/* Semicolons you got me here.. When I become president I will make sure you are bombarded with nuclear 
   weapon. No beer :( */

main()
{
	int farenheit;
	printf("%s\t%s\n", "Farenheit", "Celcius");
	for (farenheit = 300; farenheit >= 0; farenheit = farenheit - 20)
		printf("%d\t%15.1f\n", farenheit, (5.0/9.0) * (farenheit - 32.0));	
}