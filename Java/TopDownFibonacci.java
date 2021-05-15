public class TopDownFibonacci 
{
    public static long fibonacci(int n, long[] f)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (f[n] > 0)
            return f[n];
        f[n] = fibonacci(n - 1, f) + fibonacci(n - 2, f);
        return f[n];
    }

    public static void main(String[] args)
    {
        if (!Util.argMatch(args, 1))
            return;

        long[] f = new long[100];
        f[0] = 0;
        f[1] = 1;

        for (int i = 0; i < Integer.parseInt(args[0]); i++)
            System.out.print(fibonacci(i, f) + " ");
    }
}
