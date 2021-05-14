public class Seirpinski 
{
    public static Point getVertex(Point[] points)
    {
        int v = (int)(Math.random() * 3);
        return points[v];
    }

    public static void setPenColor(Point p)
    {
        if (p.Y() < Math.sqrt(3)/4 && p.X() <= 0.5)
            StdDraw.setPenColor(StdDraw.RED);
        else if (p.Y() < Math.sqrt(3)/4 && p.X() >= 0.5)
            StdDraw.setPenColor(StdDraw.GREEN);
        else
            StdDraw.setPenColor(StdDraw.BLUE);
    }

    public static void drawSeirpinski(int NUM_TRIES, Point[] points)
    {
        for (Point p : points)
            p.draw();

        Point currPoint = getVertex(points);

        for (int i = 0; i < NUM_TRIES; i++)
        {
            Point p1 = getVertex(points);
            while (Point.equal(p1, currPoint))
                p1 = getVertex(points);
            
            currPoint = Point.midPoint(currPoint, p1);
            setPenColor(currPoint);
            
            currPoint.draw();
        }
        StdDraw.show();
    }

    public static void main(String[] args) 
    {
        Point[] points = { new Point(), new Point(0.5, Math.sqrt(0.75)), 
                            new Point(1, 0) };

        StdDraw.enableDoubleBuffering();
        StdDraw.setYscale(-0.5, 1.5);
        StdDraw.setXscale(-0.5, 1.5);
        StdDraw.setPenRadius(0.001);

        int NUM_TRIES = 10000;

        drawSeirpinski(NUM_TRIES, points);
    }    
}
