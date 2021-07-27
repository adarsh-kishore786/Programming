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

    public Position(Vector v)
    {
        comp = new double[v.dim()];
        for (int i = 0; i < comp.length; i++)
            comp[i] = v.getComp(i);
    }

    @Override
    public String toString()
    {
        return "Position: " + Arrays.toString(comp);
    }
}
