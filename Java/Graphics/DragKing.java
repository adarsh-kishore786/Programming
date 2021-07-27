import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

public class DragKing extends Frame implements MouseListener, MouseMotionListener
{
    private final int WIDTH = 300;
    private final int HEIGHT = 300;

    protected Point2D[] mPoints;
    protected Point2D mSelectedPoint;

    public DragKing(String title)
    {
        setTitle(title);
        setSize(WIDTH, HEIGHT);
        setResizable(false);
        center();
        initialize();

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

    private void initialize()
    {
        mPoints = new Point2D[9];

        // Cubic curve
        mPoints[0] = new Point2D.Double(50, 75);
        mPoints[1] = new Point2D.Double(100, 100);
        mPoints[2] = new Point2D.Double(200, 50);
        mPoints[3] = new Point2D.Double(250, 75);

        // Quad curve
        mPoints[4] = new Point2D.Double(50, 175);
        mPoints[5] = new Point2D.Double(150, 150);
        mPoints[6] = new Point2D.Double(250, 175);

        // Line
        mPoints[7] = new Point2D.Double(50, 275);
        mPoints[8] = new Point2D.Double(250, 275);

        mSelectedPoint = null;
        addMouseListener(this);
        addMouseMotionListener(this);
    }
    
    private void center()
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
        drawCubic(g2);
        drawQuad(g2);
        drawLine(g2);

        for (Point2D currPoint : mPoints)
        {
            if (currPoint == mSelectedPoint)
                g2.setPaint(Color.RED);
            else
                g2.setPaint(Color.BLUE);
            g2.fill(getControlPoint(currPoint));
        }
    }

    private void drawCubic(Graphics2D g2)
    {
        Line2D tan1 = new Line2D.Double(mPoints[0], mPoints[1]);
        Line2D tan2 = new Line2D.Double(mPoints[2], mPoints[3]);
        g2.setPaint(Color.GRAY);
        g2.draw(tan1);
        g2.draw(tan2);

        CubicCurve2D c = new CubicCurve2D.Float();
        c.setCurve(mPoints, 0);
        g2.setPaint(Color.BLACK);
        g2.draw(c);
    }

    private void drawQuad(Graphics2D g2)
    {
        Line2D tan1 = new Line2D.Double(mPoints[4], mPoints[5]);
        Line2D tan2 = new Line2D.Double(mPoints[5], mPoints[6]);
        g2.setPaint(Color.GRAY);
        g2.draw(tan1);
        g2.draw(tan2);

        QuadCurve2D q = new QuadCurve2D.Float();
        q.setCurve(mPoints, 4);
        g2.setColor(Color.BLACK);
        g2.draw(q);
    }

    private void drawLine(Graphics2D g2)
    {
        Line2D l = new Line2D.Double(mPoints[7], mPoints[8]);
        g2.setPaint(Color.BLACK);
        g2.draw(l);
    }

    private Shape getControlPoint(Point2D p)
    {
        int side = 4;
        return new Rectangle2D.Double(
            p.getX() - side / 2, p.getY() - side / 2, 
                side, side
        );
    }

    public void mouseClicked(MouseEvent me) {}
    public void mousePressed(MouseEvent me)
    {
        mSelectedPoint = null;
        for (Point2D p : mPoints)
        {
            Shape s = getControlPoint(p);
            if (s.contains(me.getPoint()))
            {
                mSelectedPoint = p;
                break;
            }
        }
        repaint();
    }

    public void mouseReleased(MouseEvent me) {}
    public void mouseMoved(MouseEvent me) {}

    public void mouseDragged(MouseEvent me)
    {
        if (mSelectedPoint != null)
        {
            mSelectedPoint.setLocation(me.getPoint());
            repaint();
        }
    }

    public void mouseEntered(MouseEvent me) {}
    public void mouseExited(MouseEvent me) {}
    public static void main(String[] args) 
    {
        new DragKing("Drag King");    
    }
}
