#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i = 0;
	for (int i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	while (i < 25)
	{
		printf("%d ", i);
		i++;
	}
	return 0;
}