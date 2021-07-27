public class RecursiveSquares 
{
    public static void drawSquare(int n, double x, double y, double side)
    {
        if (n >= 1)
            return;

        if (n == 0)
        {
            StdDraw.setPenColor(StdDraw.GRAY);
            StdDraw.filledSquare(x, y, side / 2);

            StdDraw.setPenColor(StdDraw.BLACK);
            StdDraw.square(x, y, side / 2);
        }

        drawSquare(n+1, x+side/2, y+side/2, side/2);
        drawSquare(n+1, x+side/2, y-side/2, side/2);
        drawSquare(n+1, x-side/2, y+side/2, side/2);
        drawSquare(n+1, x-side/2, y-side/2, side/2);
    }    

    public static void main(String[] args) 
    {
        StdDraw.enableDoubleBuffering();
        drawSquare(0, 0.5, 0.5, 0.5);  
        
        StdDraw.show();
    }
}
