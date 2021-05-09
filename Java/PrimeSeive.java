/*
	PrimeSeive.java

	This program accepts a number from the command 
	line and prints the list of prime numbers from 
	1 to n using Sieve of Erasthothenes.
*/

public class PrimeSeive
{
	public static void primeSieve(boolean[] nums)
	{
		for (int i = 2; i < nums.length; i++)
		{
			if (!nums[i])
				continue;
			nums[i] = true;
			for (int j = i; i * j < nums.length; j++)
				nums[i * j] = false;
		}
	}

	public static void main(String[] args)
	{
		if (args.length == 0)
		{
			System.out.println("No arguments given.");
			return;
		}

		boolean[] nums = new boolean[Integer.parseInt(args[0]) + 1];
		for (int i = 2; i < nums.length; i++)
			nums[i] = true;

		primeSieve(nums);
		int total = 0;
		for (int i = 2; i < nums.length; i++)
		{
			if (nums[i])
			{
				System.out.print(i + " ");
				total++;
			}
		}
		System.out.println("\nTotal " + total + " primes.");
	}
}