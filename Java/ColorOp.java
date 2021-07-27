import java.awt.Color;

public class ColorOp 
{
    private final int r, g, b;

    public ColorOp(int r, int g, int b)
    {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public String toString()
    {
        return "Color (" + r + ", " + g + ", " + b + ")";
    }
    
    public int getLuminance()
    {
        return (int)(0.299 * r + 0.587 * g + 0.144 * b);
    }

    public ColorOp toGrayscale()
    {
        int l = getLuminance();
        return new ColorOp(l, l, l);
    }

    public static boolean isCompatible(ColorOp c1, ColorOp c2)
    {
        int l1 = c1.getLuminance();
        int l2 = c2.getLuminance();

        if (Math.abs(l1 - l2) >= 128)
            return true;
        return false;
    }
}
