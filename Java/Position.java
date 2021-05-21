import java.util.Arrays;
public class Position extends Vector 
{
    public Position(int length)
    {
        super(length);
    }

    public Position(double[] comp)
    {
        super(comp);
    }

    public Position(double mag, double[] theta)
    {
        super(mag, theta);
    }

    public Position(double mag, double angDeg)
    {
        super(mag, angDeg);
    }

    @Override
    public String toString()
    {
        return "Position: " + Arrays.toString(comp);
    }
}
