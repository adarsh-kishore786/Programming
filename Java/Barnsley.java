public class Barnsley 
{
    public static double lc(Point p, double a, double b, double c)
    {
        return a * p.X() + b * p.Y() + c;
    }

    public static Point getNext(Point p)
    {
        double v = Math.random() * 100;

        if (v >= 0 && v < 2)
            return new Point(lc(p, 0.5, 0, 0), lc(p, 0, 0.27, 0));
        else if (v < 17)
            return new Point(lc(p, -0.139, 0.263, 0.57), lc(p, 0.246, 0.224, -0.036));
        else if (v < 30)
            return new Point(lc(p, 0.17, -0.215, 0.408), lc(p, 0.222, 0.176, 0.0893));
        return new Point(lc(p, 0.781, 0.034, 0.1075), lc(p, -0.032, 0.739, 0.27));
    }

    public static void draw(int NUM_ITER)
    {
        Point currPoint = new Point(0.5, 0);
        
        for (int i = 0; i < NUM_ITER; i++)
        {
            currPoint.draw();

            currPoint = getNext(currPoint);
            StdDraw.show();
        }
    }

    public static void main(String[] args) 
    {
        int NUM_ITER = 10000;
        StdDraw.enableDoubleBuffering();

        StdDraw.setScale(-0.5, 1.5);
        StdDraw.setPenColor(StdDraw.GREEN);
        draw(NUM_ITER);
    }    
}
