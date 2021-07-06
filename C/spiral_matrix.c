#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int row)
{
    for (int i = 0; i < row * row; i++)
    {
        int pos = i;
        for (int j = i + 1; j < row * row; j++)
        {
            if ((*arr)[j] < (*arr)[pos])
                pos = j;
        }
        int temp = (*arr)[pos];
        (*arr)[pos] = (*arr)[i];
        (*arr)[i] = temp;
    }
}

void spiral(int *arr_orig, int **arr_new, int row)
{
    int max_row = row - 1;
    int min_row = -1;
    int c = 0;

    while (min_row <= max_row)
    {
        for (int j = min_row + 1; j < max_row; j++)
        {
            *(*arr_new + (min_row + 1) * row + j) = *(arr_orig + c++);
            //printf("arr_new[%d][%d]: %d\n", min_row, j, *(*arr_new + min_row * row + j));
        }
        min_row++;

        for (int i = min_row; i < max_row; i++)
            *(*arr_new + i * row + max_row) = *(arr_orig + c++);

        for (int j = max_row; j > min_row; j--)
            *(*arr_new + max_row * row + j) = *(arr_orig + c++);
        
        for (int i = max_row; i > min_row; i--) // for (int i = 2; i > -1)
            *(*arr_new + i * row + min_row) = *(arr_orig + c++);
        max_row--;
    } 
    int n = (row - 1) / 2;
    *(*arr_new + n * row + n) = *(arr_orig + c);   
}

int main()
{
    int row;
    scanf(" %d", &row);

    int *arr_orig = (int*)malloc(sizeof(int)*(row*row));
    for (int i = 0; i < row * row; i++)
        scanf("%d", arr_orig + i);
    
    int *arr_new = (int*)malloc(sizeof(int)*(row*row));

    sort(&arr_orig, row);
    spiral(arr_orig, &arr_new, row);

    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
            printf("%d ", *(arr_new + i * row + j));
        printf("\n");
    }

    printf("\n");
    return 0;
}