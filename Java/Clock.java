/*
	Clock.java

	Creates an object called clock.
*/

public class Clock 
{
	private int hours;
	private int minutes;
	private int seconds;

	public Clock(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}

	public int getHours()
	{
		return hours;
	}

	public int getMinutes()
	{
		return minutes;
	}

	public int getSeconds()
	{
		return seconds;
	}

	public void setHours(int h)
	{
		hours = h;
	}

	public void setMinutes(int m)
	{
		minutes = m;
	}

	public void setSeconds(int s)
	{
		seconds = s;
	}

	public void time()
	{
		System.out.println(hours + ":" + minutes + ":" + seconds);	
	}
}