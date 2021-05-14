public class Animation {
    public static void main(String[] args) 
    {
        StdDraw.setScale(-2, 2);
        StdDraw.enableDoubleBuffering();

        for (double t = 0; true; t += 0.02)
        {
            double x = Math.sin(t);
            double y = Math.cos(t);

            StdDraw.clear(StdDraw.BLUE);
            StdDraw.setPenColor(StdDraw.ORANGE);

            StdDraw.filledCircle(x, y, 0.05);
            StdDraw.filledCircle(-x, -y, 0.05);
            StdDraw.show();
            StdDraw.pause(20);
        }
    }
}
