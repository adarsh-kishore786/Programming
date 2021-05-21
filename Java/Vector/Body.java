public class Body 
{
    public final double G = 6.67e-11;
    protected final double mass;
    protected Position r;

    public Body(double m, double[] r)
    {
        mass = m;
        this.r = new Position(r);
    }

    public Body(double m, int dim) {
        r = new Position(dim);
        mass = m;
     }

     public Body(double m, double x, double y)
     {
         double[] pos = {x, y};
         r = new Position(pos);
         mass = m;
     }

     public Body(double m, double x, double y, double z)
     {
         double[] pos = {x, y, z};
         r = new Position(pos);
         mass = m;
     }

    public double mass() { return mass; }
    public double coord(int i) { return r.getComp(i); };

    public void setCoord(double[] coord)
    {
        assert coord.length == r.dim() : "The dimensions given (" + coord.length + 
            ") and of the radius vector (" + r.dim() + ") do not match";
        r = new Position(coord);
    }

    public String toString() {
        return "Mass of " + mass + " kg at " + r.toString();
    }

    public Force gravitationalField(Position x)
    {
        double dist = Vector.distance(r, x);
        assert !DoubleComp.equals(dist, 0) : "Distance between the points is zero";

        double mag = (G * mass) / Math.pow(dist, 2);
        Position dx = new Position(Vector.unitVector(Vector.sub(x, r)));

        return new Force(dx.scale(mag));
    }

    public Force gravitationalForce(double m, Position x)
    {
        return new Force(gravitationalField(x).scale(m));
    }

    public static void main(String[] args)
    {
        Body b = new Body(4, 1, 2);
        StdOut.println(b.toString());
        StdOut.println(b.G);

        double m = 4;
        double[] r = {2, 5};
        Position x = new Position(r);

        Force f = b.gravitationalForce(m, x);

        double[] x1 = {1, 0};
        Vector ihat = new Vector(x1);

        StdOut.println("The gravitational force on a mass " + m + " at " + x.toString() + 
                                " is " + f.toString() + " N ");
        StdOut.println("The force has magnitude " + f.mag() + " and makes angle " + 
                            Vector.angle(f, ihat) + "\u00b0 with X axis.");
    }
}
