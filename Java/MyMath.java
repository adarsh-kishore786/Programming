/*
	MyMath.java

	This class defines some math functions.
*/

public class MyMath
{
	public static int abs(int a)
	{
		if (a < 0)
			return -a;
		return a;
	}

	public static double abs(double v)
	{
		if (v < 0)
			return -v;
		return v;
	}	

	public static double evaluatePolynomial(double x, double[] xp)
	{
		double result = 0;
		for (int i = xp.size - 1; i >= 0; i--)
			result = xp[i] + x * result;
		return result;
	}

	public static int arraySum(int[] arr)
	{
		int sum = 0;
		for (int e : arr)
			sum += e;
		return sum;
	}

	public static double arraySum(double[] arr)
	{
		double sum = 0;
		for (double e : arr)
			sum += e;
		return sum;
	}

	public static double arrayAvg(int[] arr)
	{
		return arraySum(arr) * 1.0 / (arr.size);
	}

	public static double arrayAvg(double[] arr)
	{
		return arraySum(arr) / arr.size;
	}

	public static double sqrt(double c)
	{
		double result = c;

		for (int i = 0; i < 10000; i++)
			result = 1.0/2 * (result + c / result);
		return result;
	}
}