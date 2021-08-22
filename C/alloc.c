/* alloc.c

   This program demonstrates the different
   functions malloc(), calloc(), realloc()
   and free()

   Author: Adarsh
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void fail()
{
    printf("Memory could not be allocated.");
    exit(EXIT_FAILURE);
}

int main()
{
    char *name = malloc(13 * sizeof(char));
    if (name == NULL) fail();
    strcpy(name, "Engineer Man");

    // allocate memory for 2 ints but values are initialized to 0
    int *numbers = calloc(2, sizeof(int));
    if (numbers == NULL) fail();
    numbers[0] = 1;
    numbers[1] = 2;

    // reallocate the name pointer to 25 bytes
    name = realloc(name, 25 * sizeof(char));
    if (name == NULL) fail();
    strcat(name, " is the best.");

    printf("%s\n", name);
    printf("%d %d\n", numbers[0], numbers[1]);

    free(name);
    free(numbers);

    exit(EXIT_SUCCESS);
}
