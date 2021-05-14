/**
 * This class defines a 2D point in the Cartesian plane.
 */
public class Point 
{
    private double p_x;
    private double p_y;
    
    /**
     * A default constructor which initializes the Point to
     * (0, 0).
     */
    public Point()
    {
        p_x = 0;
        p_y = 0;
    }

    /**
     * A constuctor which initializes the Point to the coordinates
     * (x, y) as given in the arguments.
     * @param x The x-coordinate of the point
     * @param y The y-coordinate of the point
     */
    public Point(double x, double y)
    {
        p_x = x;
        p_y = y;
    }

    /**
     * Since the point's coordinates are declared private, the 
     * getter functions are used. This one returns the x coordinate
     * of the point.
     * 
     * @return the x coordinate of the point
     */
    public double X()
    {
        return p_x;
    }

    /**
     * Since the point's coordinates are declared private, the 
     * getter functions are used. This one returns the y coordinate
     * of the point.
     * 
     * @return the y coordinate of the point
     */
    public double Y()
    {
        return p_y;
    }

    /**
     * This function is used to render the point on screen.
     * It uses the <code>point()</code> function from the 
     * <code>StdDraw</code> class to draw the point.
     */
    public void draw()
    {
        StdDraw.point(p_x, p_y);
    }

    /**
     * This is a static function (meaning no object creation
     * is necessary to use this function). It takes in two points,
     * <code>p1</code> and <code>p2</code> which are objects of 
     * this class <code>Point</code> and finds a point p which 
     * is their mid-point.
     * 
     * @param p1 The first point
     * @param p2 The second point
     * @return The midpoint of <code>p1</code> and <code>p2</code>
     */
    public static Point midPoint(Point p1, Point p2)
    {
        double x = (p1.X() + p2.X()) / 2;
        double y = (p1.Y() + p2.Y()) / 2;
        return new Point(x, y);
    }

    /**
     * This is a static function (meaning no object creation
     * is necessary to use this function). It takes in two points,
     * <code>p1</code> and <code>p2</code> which are objects of 
     * this class <code>Point</code> and finds if the two points
     * are equal or not. It does so by comparing both their 
     * X and Y-coordinates.
     * 
     * @param p1 The first point
     * @param p2 The second point
     * @return A boolean denoting if the points are equal or not
     */
    public static boolean equal(Point p1, Point p2)
    {
        return (p1.X() == p2.X() && p1.Y() == p2.Y());
    }
}
