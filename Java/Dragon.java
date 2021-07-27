/*
	Dragon.java
*/

public class Dragon
{
	public static String reverse(String v)
	{
		String n = "";

		for (int i = 0; i < v.length(); i++)
			n = v.charAt(i) + n;
		return n;
	}

	public static String invert(String v)
	{
		String n = "";
		for (int i = 0; i < v.length(); i++)
		{
			char c = v.charAt(i);
			if (c == 'L')
				n += "R";
			else if (c == 'R')	
				n += "L";
			else
				n += c;
		}
		return n;
	}

	public static void dragonInstructions()
	{
		String inst = "F";

		for (int i = 0; i <= 5; i++)
		{
			System.out.print("Order " + i + ": ");
			System.out.println(inst);

			inst += "L" + invert(reverse(inst));
		}
	}

	public static void main(String[] args)
	{
		dragonInstructions();
	}
}