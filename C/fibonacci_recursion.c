/* fibonacci_recursion.c

   This program accepts a limit
   from the user and prints that
   number of Fibonacci numbers using
   recursion.

   Author: Adarsh
*/

# include <stdio.h>

int limit;

void fibonacci(int a, int b, int count)
{
    if (count > limit)
        return;

    printf("%d ", a);
    fibonacci(b, a+b, count + 1);
}

int main()
{

    printf("Enter number of Fibonacci terms:\n");
    scanf("%d", &limit);

    printf("Fibonacci numbers:\n");
    fibonacci(1, 1, 1);
}
