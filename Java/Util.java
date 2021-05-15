/*
	Util.java

	Contains some utilities.
*/

public class Util
{
	public static void printMatrix(int[][] matrix)
	{
		for (int[] row : matrix)
		{
			for (int e : row)
				System.out.print(String.format("%5d", e) + " ");
			System.out.println();
		}
	}

	public static boolean argMatch(String[] args, int n)
	{
		if (args.length != n)
		{
			System.out.println("Invalid number of arguments given.");
			return false;
		}
		return true;
	}
}