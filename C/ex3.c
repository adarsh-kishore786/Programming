#include <stdio.h>

int main()
{
	int age = 10;
	int height = 72;
	char c = 'A';
	float f = 12345.7;
	float f2 = 122340000.1;
	char name[] = "Ash";

	printf("My name is %s.\n", name);
	printf("I am %d years old.\n", age);
	printf("I am %d inches tall.\n", height);
	printf("I recently got an %c in my test.\n", c);
	printf("My favourite number is %f, which u can also call %e.\n", f, f);
	printf("The most convenient way to say it is %g.\n", f);
	printf("The most convenient way to say this is %g.\n", f2);

	printf("\nSqueak! There's a rat here!\a\n");
	printf("This is a \f formfeed, a section separator.\n");
	printf("This is a \v vertical tab.\n");

	printf("\nThis is %d in hexadecimal: 0x%X\n", height, height);

	char str[] = "geeksforgeeks";
	printf("Normally text is right-aligned: %20s like this\n", str);
	printf("Using - it is left-aligned   : %-20s like this\n", str);
	printf("Right-aligned zero filled    : %020s like this\n", str);

	printf("\nThe same can be done for other types of data:\n");
	printf("Integers right-aligned: %10d like this\n", age);
	printf("Integers left-aligned : %-10d like this\n", -age);
	printf("Zero filled           : %010d like this\n\n", age);

	printf("Floats right-aligned: %15f like this\n", f);
	printf("Floats left-aligned : %-15f like this\n", f);
	printf("Floats zero-filled  : %015f like this\n\n", f);
	
	printf("Exponentials right-aligned: %15e like this\n", f);
	printf("Exponentials left-aligned : %-15e like this\n", f);
	printf("Exponentials zero-filled  : %015e like this\n", f);

	printf("\nFloats can also be controlled in decimal places\n");
	printf("Two decimal places only: %.2f\n", 123.4564);
	printf("For exponentials       : %.2e\n", 123.4564);

	printf("\nCharacters:\n");
	printf("Right-aligned: %10c like this\n", c);
	printf("Left-aligned : %-10c like this\n", c);
	printf("Zero-filled  : %010c like this\n", c);

	return 0;
}