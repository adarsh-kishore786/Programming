/* malloc.c

   This program demonstrates the use of
   the malloc command, which is used for
   creating arrays with variable number
   of elements.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int max, *p;
    printf("Enter array size: ");
    scanf("%d", &max);

    p = (int*) malloc(max * sizeof(int));
    // The malloc function allocates size for
    // array during execution of program, not
    // compilation. The malloc function returns
    // a void pointer, which has to be explicitly
    // cast into an int* pointer.

    for (int i = 0; i < max; i++)
    {
        p[i] = (i + 1) * (i + 1);
        printf("%d ", p[i]);
    }
}
