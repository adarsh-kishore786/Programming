import java.util.Scanner;
import java.text.NumberFormat;

public class SimpleInterest
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("Principal: ");
		double principle = sc.nextDouble();

		System.out.print("Rate: ");
		double rate = sc.nextDouble();

		System.out.print("Years: ");
		int years = sc.nextInt();

		double si = (principle * rate * years) / 100;
		System.out.println(NumberFormat.getCurrencyInstance().format(si));
	}
}