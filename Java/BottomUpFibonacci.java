public class BottomUpFibonacci 
{
    public static long[] fibonacci(int n)
    {
        long[] f = new long[n + 1];

        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i < f.length; i++)
            f[i] = f[i - 1] + f[i - 2];
        return f;
    }    

    public static void main(String[] args) 
    {
        if (!Util.argMatch(args, 1))
            return;
            
        long[] f = fibonacci(Integer.parseInt(args[0]));
        for (long e : f)
            System.out.print(e + " ");
    }
}
