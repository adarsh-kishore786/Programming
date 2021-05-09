public class ClockMain
{
	public static void main(String args[])
	{	
		Clock c = new Clock(12, 34, 23);
		c.time();
		System.out.println(c.getHours());
	}
}