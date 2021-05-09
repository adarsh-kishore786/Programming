/*
	Hadamard.java
*/

public class Hadamard
{
	public static boolean isPowerOf2(int n)
	{
		int i = 0;
		while ((int)(Math.pow(2, i)) <= n)
		{
			if (n == (int)(Math.pow(2, i)))
				return true;
			i++;
		}
		return false;
	}

	public static boolean[][] genHadamard(int n)
	{
		boolean[][] matrix = new boolean[n][n];
		if (n == 1)
		{
			matrix[0][0] = true;
			return matrix;
		}

		boolean[][] submatrix = genHadamard(n / 2);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0 ; j < n; j++)
				matrix[i][j] = submatrix[i % (n / 2)][j % (n / 2)];
		}

		for (int i = n / 2; i < n; i++)
		{
			for (int j = n / 2; j < n; j++)
				matrix[i][j] = !matrix[i][j];
		}
		return matrix;
	}

	public static void printMatrix(boolean[][] matrix)
	{
		for (boolean[] row : matrix)
		{
			for (boolean e : row)
				if (e)
					System.out.print("T ");
				else
					System.out.print("F ");
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
		if (!isPowerOf2(n))
		{
			System.out.println("Argument is not a power of 2.");
			return;
		}

		boolean[][] matrix = genHadamard(n);
		printMatrix(matrix);
	}
}