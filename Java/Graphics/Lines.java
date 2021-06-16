import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

public class Lines extends Frame
{
    private final int WIDTH = 500;
    private final int HEIGHT = 500;

    public Lines(String title)
    {
        setTitle(title);
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
        int numLines = 25;
        Color[] mColors = { Color.RED, Color.GREEN, Color.BLUE };

        for (int i = 0; i < numLines; i++)
        {
            double ratio = (i * 1.0) / numLines;
            Line2D line = new Line2D.Double(0, ratio * HEIGHT, ratio * WIDTH, HEIGHT);
            g2.setPaint(mColors[i % mColors.length]);
            g2.draw(line);
        }
    }
    public static void main(String[] args) 
    {
        new Lines("Lines");
    }
}
