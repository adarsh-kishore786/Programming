import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;

public class Shapes extends Frame 
{
    private final int WIDTH = 500;
    private final int HEIGHT = 500;

    public Shapes(String title)
    {
        super(title);

        setSize(WIDTH, HEIGHT);
        setResizable(false);
        center();

        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                dispose();
                System.exit(0);
            }
        });

        setVisible(true);
    }

    public void center()
    {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = getSize();
        int x = (screenSize.width - frameSize.width) / 2;
        int y = (screenSize.height - frameSize.height) / 2;
        setLocation(x, y);
    }

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        GeneralPath path = new GeneralPath(GeneralPath.WIND_EVEN_ODD);
        path.moveTo(50, 50);
        path.lineTo(70, 44);
        path.curveTo(100, 10, 140, 80, 160, 80);
        path.lineTo(190, 40);
        path.lineTo(200, 56);
        path.quadTo(100, 150, 70, 60);
        path.closePath();

        GeneralPath path2 = new GeneralPath(GeneralPath.WIND_EVEN_ODD);
        path2.moveTo(10, 50);
        path2.quadTo(WIDTH/2-10, 1.5 * HEIGHT, WIDTH, 50);

        g2.draw(path);
        g2.setColor(Color.BLUE);

        g2.fill(path);

        g2.setColor(Color.RED);
        g2.draw(path2);

        System.out.println("Path of bird: ");
        printPath(path.getPathIterator(null));

        System.out.println("Path of parabola: ");
        printPath(path2.getPathIterator(null));
    }

    public void printPath(PathIterator p)
    {
        for (; !p.isDone(); p.next())
        {
            System.out.println("Start:");
            double[] coordinates = new double[6];

            int type = p.currentSegment(coordinates);
            switch (type)
            {
                case PathIterator.SEG_MOVETO: 
                    System.out.println("Move to (" + coordinates[0] + ", " + coordinates[1] + ")");
                    break;
                case PathIterator.SEG_LINETO:
                    System.out.println("Line to (" + coordinates[0] + ", " + coordinates[1] + ")");
                    break;
                case PathIterator.SEG_QUADTO:
                    System.out.println("Quad to (" + coordinates[0] + ", " + coordinates[1] + "), (" +
                                            coordinates[2] + ", " + coordinates[3] + ")");
                    break;
                case PathIterator.SEG_CUBICTO:
                    System.out.println("Cube to (" + coordinates[0] + ", " + coordinates[1] + "), (" +
                                            coordinates[2] + ", " + coordinates[3] + "), (" + 
                                            coordinates[4] + ", " + coordinates[5] + ")");
                    break;
                case PathIterator.SEG_CLOSE:
                    System.out.println("Closed curve");
                    break;
            }
        }
        System.out.println("Done\n");
    }

    public static void main(String[] args)
    {
        new Shapes("Shapes Demo");
    }
}
