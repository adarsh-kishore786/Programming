import java.util.Arrays;

public class Force extends Vector
{
    public Force(int length)
    {
        super(length);
    }

    public Force(double[] comp)
    {
        super(comp);
    }

    public Force(double mag, double[] theta)
    {
        super(mag, theta);
    }

    public Force(double mag, double angDeg)
    {
        super(mag, angDeg);
    }
    
    @Override
    public String toString()
    {
        String s = "Force is: " + Arrays.toString(comp);
        return s;
    }
}
