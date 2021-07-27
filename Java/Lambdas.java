import java.util.function.*;

public class Lambdas
{
	public static <V> Function<V, V> identityFunction()
	{
		return value -> value;
	}

	public static <V> Function<V, V> identifyFunctionAIC()
	{
		return new Function<V, V>()
		{
			@Override
			public V apply(V value)
			{
				return value;
			}
		};
	}

	public static void main(String[] args) 
	{
	}
}