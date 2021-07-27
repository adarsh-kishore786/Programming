#include <stdio.h>

int main()
{
	char full_name[] = 
	{
		'Z', 'e', 'd',
		' ', 'A', '.', ' ',
		'S', 'h', 'a', 'w', '\0'
	};

	int areas[] = {10, 12, 13, 14, 20};
	areas[0] = 'Z';
	char name[] = "Zed";

	printf("The size of an int: %u\n", sizeof(int));
	printf("The size of areas(int[]): %u\n", sizeof(areas));
	printf("The number of ints in the area: %u\n", 
				sizeof(areas)/sizeof(int));
	printf("The first area is %d, the 2nd is %d.\n", areas[0], 
				areas[1]);
	printf("The size of a char: %u\n", sizeof(char));
	printf("The size of name: %u\n", sizeof(name));
	printf("Number of characters in name: %u\n", sizeof(name)/sizeof(char));
	printf("Number of characters in full name: %u\n", 
					sizeof(full_name),sizeof(char));

	printf("Name = %s and full name = %s\n", name, full_name);

	return 0;
}