#include <stdio.h>

float farenheit_to_celcius(int fahrenheit);

main() 
{
	int fahrenheit = 0;
	
	while(fahrenheit <= 300) {
		printf("%4d %6.1f %s", fahrenheit, farenheit_to_celcius(fahrenheit), "\n");
		fahrenheit = fahrenheit + 20;
	}
}

float farenheit_to_celcius(int fahrenheit)
{
	float celcius;
	celcius = (5.0/9.0) * (fahrenheit - 32.0);
	return celcius;
}