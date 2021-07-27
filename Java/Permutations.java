/*
	Permutations.java

	This program accepts n and prints the possible 
	n! combinations using alphabets.
*/

import java.util.Arrays;

public class Permutations
{
	public static int fact(int n)
	{
		if (n == 0 || n == 1)
			return 1;
		return n * fact(n - 1);
	}

	public static String remove(String s, int pos)
	{
		String n = "";
		for (int i = 0; i < s.length(); i++)
			if (i != pos)
				n += s.charAt(i);
		return n;
	}

	public static String insert(String s, char c, int pos)
	{
		String n = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (i == pos)
				n += "" + c + s.charAt(i);
			else
				n += s.charAt(i);
		}
		if (pos == s.length())
			n += c;
		return n;
	}

	public static String reverse(String s)
	{
		String n = "";
		for (int i = s.length() - 1; i >= 0; i--)
			n += s.charAt(i);
		return n;
	}

	public static String permute(String s, int pos)
	{
		int l = s.length();

		if (l == 1)
			return s;
		
		if (l == 2)
			return "" + s.charAt(1) + s.charAt(0);

		String temp = remove(s, 0);
		String p = permute(temp, pos);
		return insert(p, s.charAt(0), pos);
	}
	public static void main(String[] args) 
	{
		// if (!Util.argMatch(args, 1))
		// 	return;

		int n = 4;
		String[] s = new String[fact(n)];
		for (int i = 0; i < s.length; i++)
			s[i] = "";

		String alpha = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < n; i++)
			s[0] += alpha.charAt(i);
		
		int c = 0;
		int val = fact(n - 1);

		for (int i = 1; i < s.length; i++)
		{
			if (i % val == 0)
			{
				c++;
				s[i] = insert(remove(s[0], 0), 'a', c);
				continue;
			}
			s[i] = permute(s[0], c);
		}
		System.out.println(Arrays.toString(s));
	}
}