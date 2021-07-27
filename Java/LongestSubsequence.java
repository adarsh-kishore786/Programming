/*
	LongestSubsequence.java

	Given two different sequences, this program finds 
	the longest common subsequence between them.
*/

import java.util.Arrays;
public class LongestSubsequence 
{
	public static int max(int s1, int s2)
	{
		if (s1 > s2)
			return s1;
		return s2;
	}

	/**
	 * This finds the longest subsequence common in two sequences.
	 * 
	 * For example, if 
	 * a = {1, 2, 3, 4, 5, 7};
	 * b = {1, 2, 3, 8, 5, 7};
	 * Then subseq = {1, 2, 3, 5, 7}
	 * whose length is 5
	 * 
	 * @param i The current position in first sequence
	 * @param j The current position in second sequence
	 * @param a The first sequence
	 * @param b The second sequence
	 * @return Length of the LCS of <code>a</code> and <code>b</code>
	 */
	public static int lcs(int i, int j, int[] a, int[] b)
	{
		if (i == a.length || j == b.length)
			return 0;
		
		if (a[i] == b[j])
			return 1 + lcs(i + 1, j + 1, a, b);
		return max(lcs(i, j+1, a, b), lcs(i+1, j, a, b));
	}

	public static int[] getLcs(int i, int j, int[] a, int[] b, int[] lcs, int c)
	{
		if (i == a.length || j == b.length)
			return lcs;
		if (a[i] == b[j])
		{
			lcs[c] = a[i];
			return getLcs(i+1, j+1, a, b, lcs, c+1); 
		}
		if (lcs(i, j+1, a, b) > lcs(i+1, j, a, b))
			return getLcs(i, j+1, a, b, lcs, c);
		return getLcs(i+1, j, a, b, lcs, c);
	}

	public static void main(String[] args)
	{
		int[] a = {1, 2, 3, 4, 5, 2, 8};
		int[] b = {1, 2, 3, 8, 5, 7, 8};
		
		int lcsLength = lcs(0, 0, a, b);
		int[] l = new int[lcsLength];
		System.out.println("lcs(a, b) = " + Arrays.toString(getLcs(0, 0, a, b, l, 0)));
	}
}