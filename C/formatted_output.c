/* formatted_output.c

   This program prints the output
   in a certain format.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char *book[] = {
		"Discovery of India",
		"My Experiments with Truth",
		"Sunny Days",
		"One More Over"
	};

	char *author[] = {
		"Jawaharlal Nehru",
		"Mahatma Gandhi",
		"Sunil Gavaskar",
		"Erapalli Prasanna"
	};

	float price[4] = {
		425.50,
		375.50,
		95.50,
		85.00
	};

	int s1 = strlen(book[1]);
	int s2 = strlen(author[3]);
	int s3 = 6;

	for (int i = 0; i < 4; i++)
		printf("%*s\t%*s\t%*.2f\n", s1, book[i], 
			s2, author[i], s3, price[i]);
}