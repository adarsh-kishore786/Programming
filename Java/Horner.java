/*
	Horner.java

	This program evaluates a polynomial equation 
	whose coefficients are given by the user.
*/

public class Horner 
{
	public static double[] init(String[] args)
	{
		double xp[] = new double[args.length - 1];
		for (int i = 0; i < xp.length; i++)
			xp[i] = Double.parseDouble(args[i]);

		return xp;
	}

	public static double evaluate(double[] xp, double x)
	{
		double result = 0;
		for (int i = xp.length - 1; i >= 0; i--)
			result = (xp[i] + x * result);
		return result; 
	}

	public static int fact(int n)
	{
		if (n == 0 || n == 1)
			return 1;
		return n * fact(n - 1);
	}

	public static double exp(double x)
	{
		double xp[] = new double[19];
		for (int i = 0; i < xp.length; i++)
			xp[i] = 1.0 / fact(i);

		return evaluate(xp, x);
	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.out.println("Invalid number arguments given.");
			return;
		}

		double x = Double.parseDouble(args[0]);

		System.out.println("Built-in: " + Math.exp(x));
		System.out.println("User-def: " + exp(x));
	} 
}