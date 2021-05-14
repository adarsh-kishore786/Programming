/*
	Matrix.java

	Implements an API for a matrix.
*/

public class Matrix 
{
	private static void error(int a, int b)
	{
		System.out.println("The vectors of length " + a + " and " + b + 
			" aren\'t compatible for this operation.");
		return;
	}

	private static void error(int r1, int c1, int r2, int c2)
	{
		System.out.println("The matrices of order (" + r1 + " x " + c1 + 
			") and (" + r2 + " x " + c2 + ") are not compatible for this " +
			"operation.");
		return;
	}

	/**
	 * Checks if the length of two vectors is the same
	 * or not.
	 */
	private static boolean equallength(double[] a, double[] b)
	{
		int s1 = a.length;
		int s2 = b.length;

		if (s1 != s2)
		{
			error(s1, s2);
			return false;
		}
		return true;
	}

	/*
	 * Checks if the order of two matrices is the same
	 * or not.
	 */
	// private static boolean equallength(double[][] a, double[][] b)
	// {
	// 	if ((a.length != b.length) || (a[0].length != b[0].length))
	// 	{
	// 		error(a.length, a[0].length, b.length, b[0].length);
	// 		return false;
	// 	}
	// 	return true;
	// }

	/*
	 * Checks if the two matrices are compatible for 
	 * matrix multiplication or not.
	 */
	private static boolean canMultiply(double[][] a, double[][] b)
	{
		if (a[0].length != b.length)
		{
			error(a.length, a[0].length, b.length, b[0].length);
			return false;
		}
		return true;
	}

	private static boolean canMultiply(double[][] a, double[] b)
	{
		if (a[0].length != b.length)
		{
			error(a.length, a[0].length, b.length, 1);
			return false;
		}
		return true;
	}

	private static boolean canMultiply(double[] x, double[][] a)
	{
		if (a.length != x.length)
		{
			error(1, x.length, a.length, a[0].length);
			return false;
		}
		return true;
	}

	public static double dot(double[] a, double[] b)
	{
		if (!equallength(a, b))
			return Double.NaN;

		double s = 0.0;
		for (int i = 0; i < a.length; i++)
			s += a[i] * b[i];
		return s;
	}

	public static double[][] multiply(double[][] a, double[][] b)
	{
		if (!canMultiply(a, b))
			return null;

		double[][] c = new double[a.length][b[0].length];
		for (int i = 0; i < a.length; i++)
		{
			for (int j = 0; j < b[0].length; j++)
			{
				for (int k = 0; k < b.length; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		}
		return c;
	}

	public static double[][] transpose(double[][] a)
	{
		double[][] b = new double[a[0].length][a.length];
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j < a[i].length; j++)
				b[j][i] = a[i][j];
		return b;
	}

	public static double[] multiply(double[][] a, double[] x)
	{
		double[][] y = new double[x.length][1];
		for (int i = 0; i < x.length; i++)
			y[i][0] = x[i];
		
		double[][] temp = multiply(a, y);
		double[] z = new double[a.length];

		for (int i = 0; i < temp.length; i++)
			z[i] = temp[i][0];
		return z;
	}

	public static double[] multiply(double[] x, double[][] a)
	{
		if (!canMultiply(x, a))
			return null;
		
		double[][] c = new double[1][x.length];
		for (int i = 0; i < x.length; i++)
		{
			for (int j = 0; j < a[0].length; j++)
				c[0][i] += x[i] * a[i][j];
		}
		double[] result = new double[x.length];
		for (int i = 0; i < result.length; i++)
			result[i] = c[0][i];
		return result;	
	}
}