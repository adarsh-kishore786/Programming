/*
	PascalTriangle.java

	This program accepts value of n from command
	line and prints the first n rows of Pascal's triangle.
*/

public class PascalTriangle
{	
	public static void genPascal(int[][] matrix)
	{
		for (int i = 0; i < matrix.length; i++)
			matrix[i][0] = 1;

		if (matrix.length > 1)
			matrix[1][1] = 1;

		for (int i = 2; i < matrix.length; i++)
		{
			matrix[i][i] = 1;
			for (int j = 1; j < i; j++)
				matrix[i][j] = matrix[i - 1][j] + matrix[i-1][j-1];
		}
	}

	public static void printMatrix(int[][] matrix)
	{
		for (int[] row : matrix)
		{
			for (int e : row)
				if (e != 0)
					System.out.print(e + " ");
				else
					break;
			System.out.println();
		}			
	}

	public static void main(String[] args) 
	{
		if (args.length != 1)
		{
			System.out.println("Invalid number of arguments.");
			return;
		}	

		int n = Integer.parseInt(args[0]);
		int[][] pascal = new int[n][n];
		genPascal(pascal);

		printMatrix(pascal);
	}
}