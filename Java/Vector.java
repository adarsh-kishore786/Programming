import java.util.Arrays;

public class Vector
{
    protected double[] comp;
    
    protected Vector() {}

    public Vector(int dim)
    {
        comp = new double[dim];
    }

    public Vector(double[] val)
    {
        comp = new double[val.length];
        for (int i = 0; i < val.length; i++)
            comp[i] = val[i];
    }

    public Vector(double mag, double[] theta)
    {
        double sum = 0.0;
        for (double e : theta)
            sum += Math.pow(Math.cos(e), 2);
        assert(DoubleComp.equals(sum, 1.0));

        double[] comp = new double[theta.length];
        for (int i = 0; i < comp.length; i++)
            comp[i] = mag * Math.cos(theta[i]);
    }

    public Vector(double mag, double angDeg)
    {
        double ang[] = new double[2];
        ang[0] = angDeg;
        ang[1] = 90.0 - angDeg;
    }

    public void setComponent(double[] val)
    {
        comp = new double[val.length];
        for (int i = 0; i < val.length; i++)
            comp[i] = val[i];
    }

    public int dim()
    {
        return comp.length;
    }

    public double mag()
    {
        double sum = 0;
        for (double e : comp)
            sum += e * e;
        return Math.sqrt(sum);
    }

    public double getComp(int i)
    {
        assert(i < comp.length);
        return comp[i];
    }

    public Vector negate()
    {   
        return scale(-1);
    }

    public Vector scale(double alpha)
    {
        int l = comp.length;
        double[] ncomp = new double[l];

        for (int i = 0; i < l; i++)
            ncomp[i] = alpha * comp[i];
        return new Vector(ncomp);
    }

    public static Vector add(Vector v1, Vector v2)
    {
        int l = v1.dim();
        assert(l == v2.dim());

        double[] newcomp = new double[l];
        for (int i = 0; i < newcomp.length; i++)
            newcomp[i] = v1.getComp(i) + v2.getComp(i);
        return new Vector(newcomp);
    }

    public static Vector sub(Vector v1, Vector v2)
    {
        return add(v1, v2.negate());
    }

    public static double dot(Vector v1, Vector v2)
    {
        int l = v1.dim();
        assert(l == v2.dim());

        double sum = 0;
        for (int i = 0; i < l; i++)
            sum += v1.getComp(i) * v2.getComp(i);
        return sum;
    }

    public static double dot(Vector v1, Vector v2, double angDeg)
    {
        double ang = Math.toRadians(angDeg);
        return v1.mag() * v2.mag() * Math.cos(ang);
    }

    public static double angle(Vector v1, Vector v2)
    {
        double d = dot(v1, v2);
        double l1 = v1.mag();
        double l2 = v2.mag();

        double ang = Math.acos(d / (l1 * l2));
        return Math.toDegrees(ang);
    }

    public static boolean equals(Vector v1, Vector v2)
    {
        int l = v1.dim();
        if (l != v2.dim())
            return false;

        for (int i = 0; i < l; i++)
            if (v1.getComp(i) != v2.getComp(i))
                return false;
        return true;
    }

    public String toString()
    {
        String s = "Vector of dimension " + comp.length;
        s += " =\n" + Arrays.toString(comp);

        return s;
    }
}
