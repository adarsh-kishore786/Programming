import java.text.NumberFormat;

public class NumFormatMain
{
	public static void main(String[] args)
	{
		NumberFormat currency = NumberFormat.getCurrencyInstance();
		String result = currency.format(12345567.891);
		System.out.println(result);

		NumberFormat percent = NumberFormat.getPercentInstance();
		result = percent.format(0.1);
		System.out.println(result);
	}
}