/*
	Shuffling.java

	This program generates a random permutation
	of an array of elements and prints it.
*/

public class Shuffling
{
	public static void printArray(int[] a)
	{
		for (int e : a)
			System.out.print(e + " ");
		System.out.println();
	}

	public static void shuffle(int[] a)
	{
		for (int i = 0; i < a.length; i++)
		{
			int r = i + (int)(Math.random() * (a.length - i));
			int temp = a[i];
			a[i] = a[r];
			a[r] = temp; 
		}
	}

	public static void main(String[] args) 
	{
		if (args.length != 1)
		{
			System.out.println("Invalid number of arguments.");
			return;
		}

		int[] a = new int[Integer.parseInt(args[0])];
		for (int i = 0; i < a.length; i++)
			a[i] = i;

		System.out.println("Original array: ");
		printArray(a);

		for (int i = 0; i < 10; i++)
		{
			System.out.println("\nShuffled array: ");
			shuffle(a);
			printArray(a);
		}
	}
}
