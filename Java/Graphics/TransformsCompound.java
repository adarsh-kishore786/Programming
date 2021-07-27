import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

public class TransformsCompound extends Frame 
{
    private final int WIDTH = 500;
    private final int HEIGHT = 400;

    private final int cx = (int) (WIDTH / 1.65);
    private final int cy = (int) (HEIGHT / 1.65);
    
    private void center()
    {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension frameSize = getSize();
        int x = (screenSize.width - frameSize.width) / 2;
        int y = (screenSize.height - frameSize.height) / 2;

        setLocation(x, y);
    }

    public TransformsCompound(String title)
    {
        setTitle(title);
        setSize(WIDTH, HEIGHT);
        setResizable(false);
        center();
        setBackground(Color.GRAY);

        addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent we)
            {
                dispose();
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        AffineTransform at = AffineTransform.getTranslateInstance(cx, cy);
        at.scale(-1.5, 1.5);
        at.shear(-0.5, 0);
        at.rotate(-Math.PI / 6);
        g2.setTransform(at);

        int gridSpace = 50;
        drawGrid(g2, gridSpace, 1);
        drawRectangle(g2, gridSpace, 1);
    }

    private void drawGrid(Graphics2D g, int gridSpace, double alpha)
    {
        for (int i = 0; i * gridSpace <= WIDTH; i++)
        {
            if (i == 0)
                g.setPaint(Color.RED);
            else
                g.setPaint(Color.BLACK);

            g.drawLine(i * gridSpace, -HEIGHT, i * gridSpace, HEIGHT);
            g.drawLine(-i * gridSpace, -HEIGHT, -i * gridSpace, HEIGHT);
        }

        for (int j = 0; j * gridSpace <= HEIGHT; j++)
        {
            if (j == 0)
                g.setPaint(Color.RED);
            else
                g.setPaint(Color.BLACK);
            
            g.drawLine(-WIDTH, j * gridSpace, WIDTH, j * gridSpace);
            g.drawLine(-WIDTH, -j * gridSpace, WIDTH, -j * gridSpace);
        }
    }

    private void drawRectangle(Graphics2D g, int gridSpace, double alpha)
    {
        g.setPaint(Color.RED);
        g.fillRect(0, -gridSpace, gridSpace, gridSpace);
    }
    public static void main(String[] args)
    {
        new TransformsCompound("Transform Compound");
    }
}
