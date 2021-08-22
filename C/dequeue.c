/* dequeue.c

   A dequeue is an ordered set of
   elements in which elements can be inserted or
   retrieved from either end. This program
   attempts to simulate a dequeue.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

int MAX;

void display(int* dequeue, int length)
{
    printf("\nCurrently dequeue:\n");
    for (int i = 0; i < length; i++)
        printf("%d ", *(dequeue + i));
    printf("\n");

    printf("Current length: %d\n\n", length);
}

void insert_left(int *dequeue, int val, int *currlength)
{
    for (int i = *currlength + 1; i >= 1; i--)
        *(dequeue + i) = *(dequeue + i - 1);
    *(dequeue) = val;
    ++*currlength;
}

void insert_right(int *dequeue, int val, int *currlength)
{
    *(dequeue + *currlength) = val;
    ++*currlength;
}

int retrieve_left(int *dequeue, int *currlength)
{
    int val = *dequeue;
    for (int i = 0; i < *currlength - 1; i++)
        *(dequeue + i) = *(dequeue + i + 1);
    --*currlength;
    return val;
}
int retrieve_right(int *dequeue, int *currlength)
{
    int val = *(dequeue + *currlength - 1);
    --*currlength;

    return val;
}

int choice()
{
    int ch;
    printf("\nChoose what to do:\n");
    printf("1. Insert from left\n");
    printf("2. Insert from right\n");
    printf("3. Retrieve from left\n");
    printf("4. Retrieve from right\n");
    printf("5. Quit\n");

    scanf(" %d", &ch);
    return ch;
}

int main()
{
    int currlength = 0;
    int *dequeue;
    printf("------Dequeue------\n");

    printf("Enter the maximum length of dequeue:\n");
    scanf(" %d", &MAX);

    dequeue = (int*) malloc(MAX * sizeof(int));

    display(dequeue, currlength);

    int ch = choice();

    while (ch != 5)
    {
        switch (ch)
        {
            case 1: if (currlength == MAX)
                    {
                        printf("The dequeue is full.\n");
                        break;
                    }
                    int val;
                    printf("Enter value to be inserted:\n");
                    scanf(" %d", &val);
                    insert_left(dequeue, val, &currlength);
                    display(dequeue, currlength);
                    break;
            case 2: if (currlength == MAX)
                    {
                        printf("The dequeue is full.\n");
                        break;
                    }
                    printf("Enter value to be inserted:\n");
                    scanf(" %d", &val);
                    insert_right(dequeue, val, &currlength);
                    display(dequeue, currlength);
                    break;
            case 3: if (currlength == 0)
                    {
                        printf("The dequeue is empty.");
                        break;
                    }
                    val = retrieve_left(dequeue, &currlength);
                    printf("The retrieved value is: %d", val);
                    display(dequeue, currlength);
                    break;
            case 4: if (currlength == 0)
                    {
                        printf("The dequeue is empty.\n");
                        break;
                    }
                    val = retrieve_right(dequeue, &currlength);
                    printf("The retrieved value is: %d", val);
                    display(dequeue, currlength);
                    break;
        }
        ch = choice();
    }
}
