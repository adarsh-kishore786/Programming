public class DoubleComp 
{
    private static final double epsilon = 0.001;
    
    public static boolean equals(double v1, double v2)
    {
        double diff = Math.abs(v1 - v2);

        if (diff < epsilon)
            return true;
        return false;
    }

    public static boolean ge(double v1, double v2)
    {
        double df = v1 - v2;
        if (df > epsilon)
            return true;
        return false;
    }

    public static boolean le(double v1, double v2)
    {
        return ge(v2, v1);
    }
}
