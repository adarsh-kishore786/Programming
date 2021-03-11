/* fibonacci_words.c

   This program accepts two letters
   from the user and generates a 
   Fibonacci series using them.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max_len = 128;

void fibonacci(char *f0, char *f1, int count)
{
	if (count == 0)
		return;

    printf("%s ", f0);

    if (strlen(f0) + strlen(f1) >= max_len)
    {
    	max_len += strlen(f0) + strlen(f1);
    	f0 = realloc(f0, max_len * sizeof(char));
    	f1 = realloc(f1, max_len * sizeof(char));
    }

    strrev(strcat(strrev(f0), strrev(f1)));
    strrev(f1);

    fibonacci(f1, f0, count - 1);
}

int main()
{
	char *f0, *f1;
	int count;

	f0 = malloc(max_len * sizeof(char));
	f1 = malloc(max_len * sizeof(char));

	printf("Enter two letters/words:\n");
	gets(f0);
	fflush(stdin);

	gets(f1);
	fflush(stdin);

	printf("Enter the number of terms:\n");
	scanf("%d", &count);
	fflush(stdin);

	printf("\nThe Fibonacci series starting with these:\n");
	fibonacci(f0, f1, count);

	exit(0);
}