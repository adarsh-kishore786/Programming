public interface Greeter
{
	String createGreeting(String whom);
}

public class AnonymousInnerClass
{
	public static void main(String[] args)
	{
		final String greeting = "Hello, ";

		Greeter greeter = new Greeter() {
			@Override
			public String createGreeting(String whom) {
				// Close (ie: capture) the variable here
				return greeting + whom + "!";
			}
		};

		greetWorld(greeter);


	public static void greetWorld(Greeter greeter) {
		// Have the greeter use the closed variable here
		// Note that the "greeting" variable is out of scope
		System.out.println(greeter.createGreeting("World"));
	}
}