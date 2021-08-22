/* insertion_sort.c

   This program accepts an array
   from the user and sorts it in
   the order the user wants using
   insertion sort.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

int print_list(int l[], int length)
{
    printf("Elements of the list:\n");
    for (int i = 0; i < length; i++)
        printf("%d ", l[i]);
    printf("\n");
}

void insertion_sort(int l[], int length, int asc)
{
    for (int i = 1; i < length; i++)
    {
        int pos = -1;
        for (int j = 0; j < i; j++)
        {
            if (l[j] > l[i] && asc)
            {
                pos = j;
                break;
            }
            if (l[j] < l[i] && !asc)
            {
                pos = j;
                break;
            }
            // Code for descending
        }
        if (pos != -1)
        {
            for (int j = i - 1; j >= pos; j--)
            {
                int a = l[j];
                l[j] = l[j + 1];
                l[j + 1] = a;
            }
        }
    }
}

int main()
{
    int length, *list;

    printf("Enter the number of elements in the array: ");
    scanf(" %d", &length);

    list = (int*) malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        printf("Enter a number: ");
        scanf("%d", (list + i));
    }
    int asc;
    printf("Enter the order of arrangement.\n");
    printf("1 for ascending, 0 for descending:\n");
    scanf(" %d", &asc);

    print_list(list, length);

    insertion_sort(list, length, asc);
    printf("The list is now sorted.\n");

    print_list(list, length);
    return 0;
}
