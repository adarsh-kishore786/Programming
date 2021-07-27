/*
	saddle_pt_matrix.c

	This program inputs a matrix from 
	the user and finds its saddle points.
	A saddle point is an element of matrix
	which is the smallest element in its row
	and largest element in its column.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Position
{
	int r;
	int c;
} Position;

void print_matrix(int **matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main()
{
	int m, n;
	printf("Enter the number of rows and columns: ");
	fscanf(stdin, "%d %d", &m, &n);

	int **matrix = (int**) malloc(m * sizeof(int*));

	printf("\nEnter elements of matrix:\n");

	for (int i = 0; i < m; i++)
	{
		matrix[i] = (int*) malloc(n * sizeof(int));

		for (int j = 0; j < n; j++)
		{
			printf("Enter matrix[%d][%d]: ", i, j);
			fscanf(stdin, "%d", *(matrix + i) + j);
		}
		printf("\n");
	}

	static Position min_row_pos[n];
	static Position max_col_pos[m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = max_col_pos[i].r;
			int y = max
			if (matrix[i][j] > max_col_pos[i])
			{

			}
		}
	}


	print_matrix(matrix, m, n);
}