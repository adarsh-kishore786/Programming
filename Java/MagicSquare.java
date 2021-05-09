/*
	MagicSquare.java

	Takes in an odd number n and generates an n x n 
	magic square.
*/

public class MagicSquare 
{
	public static int[][] genMagicSquare(int n)
	{
		int[][] matrix = new int[n][n];

		int i = 2;
		int row = n - 1;
		int col = row / 2;
		matrix[row][col] = 1;

		while (i <= n*n)
		{
			int r = (row + 1) % n;
			int c = (col + 1) % n;

			if (matrix[r][c] != 0)
			{
				r = (row - 1) % n;
				c = col;
				if (r < 0) r = n + r;
			}
			matrix[r][c] = i;
			row = r;
			col = c;
			i++;
		}
		return matrix;
	}

	public static void main(String[] args) 
	{
		if (args.length != 1)
		{
			System.out.println("Invalid number of arguments.");
			return;
		}	

		int n = Integer.parseInt(args[0]);

		if (n % 2 == 0)
		{
			System.out.println("Size must be odd.");
			return;
		}
		int[][] matrix = genMagicSquare(n);

		Util u = new Util();
		u.printMatrix(matrix);	
	}
}