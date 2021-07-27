/* printf_function.c

   This program demonstrates the use of
   the printf() statement.

   Author: Adarsh
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int avg = 346;
	float per = 69.2;

	printf("Average: %d\nPercentage: %f\n", avg, per);

	short unsigned int a = 32;
	printf("Unsigned int a: u %u\n", a);

	short signed int b = -10;
	printf("Signed int b: d or i: %i\n", b);

	long signed int c = -1234433443;
	printf("Long signed int c: ld %ld\n", c);

	long unsigned int d = 987654321;
	printf("Long unsigned int d: lu %lu\n", d);

	long long int e = pow(2, 62);
	printf("Long long int e: lld %lld\n", e);

	float f1 = 34.5231;
	printf("float f1: f %f\n", f1);

	double f2 = 34.5254674;
	printf("double f2: lf %lf\n", f2);

	signed char g = -127;
	printf("signed char g: %c\n", g);

	unsigned char h = 65; 
	printf("unsigned char h: %c\n\n", h);

	// Field formatting
	int weight = 63;
	printf("Weight is %d kg\n", weight);
	printf("Weight is %2d kg\n", weight);
	printf("Weight is %4d kg\n", weight);
	printf("Weight is %6d kg\n", weight);
	printf("Weight is %-6d kg\n", weight); // Left align
	printf("Weight is %1d kg\n", weight);

	// Specifying field width
	printf("\n%10.1f %10.1f %10.1f\n", 5.0, 13.5, 133.9);
	printf(  "%10.1f %10.1f %10.1f\n\n", 305, 1200.91, 3005.3);

	// Can be used with strings
	char firstname1[] = "Sandy";
	char surname1[] = "Malya";
	char firstname2[] = "Ajay Kumar";
	char surname2[] = "Gurubaxani";

	printf("%20s%20s\n", firstname1, surname1);
	printf("%20s%20s\n", firstname2, surname2);

	// Escape sequences
	printf("The new line: n \n");
	printf("Backspace: moves cursor one place b\back overwriting the b of back.\n");
	printf("The \tTab moves to the next tab: t\n");
	printf("The alert: a \a\n");
	printf("The \' single quote and \" double quote and \\ backslash\n");	
	printf("The carriage return moves to back of l\rine r\n");
}