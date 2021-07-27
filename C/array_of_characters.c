/* array_of_characters.c

   This program demonstrates handling
   multiple strings using an array.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>

#define FOUND 1
#define NOTFOUND 0

int main()
{
	char masterlist[6][20] =
		{
			"akshay",
			"parag",
			"raman",
			"srinivas",
			"gopal",
			"rajesh"
		};
	int flag, a;
	char yourname[20];

	printf("Enter your name:\n");
	gets(yourname);
	fflush(stdin);
	flag = NOTFOUND;

	for (int i = 0; i <= 5; i++)
	{
		a = strcmp(masterlist[i], yourname);
		if (a == 0)
		{
			printf("Welcome, you can enter the palace.\n");
			flag = FOUND;
			break;
		}
	}

	if (flag == NOTFOUND)
		printf("Tresspasser! Shoot the fugitive!");
	return 0;
}