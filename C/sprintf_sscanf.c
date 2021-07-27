/* sprintf_sscanf.c

   This program demonstrates the
   use of the sprintf() and the
   sscanf() function.

   Author: Adarsh
*/

#include <stdio.h>

int main()
{
	int i = 10;
	char ch = 'A';
	float a = 3.14;
	char str[20];

	printf("%d %c %f\n", i, ch, a);

	// the sprintf() function prints to a 
	// string, not to the console

	sprintf(str, "%d %c %f", i, ch, a); // stored in str 
	printf("%s\n", str);

	char str1[20] = "123 Hello 2.718";
	int int_val;
	char str_val[10];
	float fl_val;

	sscanf(str1, "%d %s %f", &int_val, str_val, &fl_val);

	printf("%s %f %d\n", str_val, fl_val, int_val);
}