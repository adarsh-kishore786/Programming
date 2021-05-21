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

    public Force(Vector v)
    { 
        comp = new double[v.dim()];
        for (int i = 0; i < comp.length; i++)
            comp[i] = v.getComp(i);
    }
    
    @Override
    public String toString()
    {
        String s = "Force: " + Arrays.toString(comp);
        return s;
    }
}
