public class TestStdDraw
{
    public static void main(String[] args)
    {
        StdDraw.setPenRadius(0.01);
        StdDraw.setPenColor(StdDraw.BLUE);
        StdDraw.point(0.5, 0.5);
        
        StdDraw.setPenColor(StdDraw.MAGENTA);
        StdDraw.line(0.2, 0.2, 0.8, 0.2);

        StdDraw.filledEllipse(0.5, 0.2, 0.5, 0.25);

        StdDraw.setPenColor(StdDraw.CYAN);
        StdDraw.arc(0.1, 0.1, 0.7, 45, 90);

        StdDraw.setPenColor(0, 0, 0);
        double[] x = { 0.1, 0.2, 0.3, 0.2, 0.6 };
        double[] y = { 0.2, 0.3, 0.2, 0.1, 0.7 };
        StdDraw.polygon(x, y);

        StdDraw.text(0.7, 0.7, "TestStdDraw");
    }
}