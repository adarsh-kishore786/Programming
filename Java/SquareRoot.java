/*
	SquareRoot.java

	This program takes a number and prints its square root
	using Newton's method.
*/

public class SquareRoot
{
	public static double sqrt(double x, double c)
	{
		for (int i = 0; i <= 100; i++)
			x =  1/2.0 * (x + c/x);
		return x;
	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.out.println("Invalid number of arguments given.");
			return;
		}

		double c = Double.parseDouble(args[0]);
		System.out.println("(" + c + ")^(0.5) = " + sqrt(1, c));
	}
}