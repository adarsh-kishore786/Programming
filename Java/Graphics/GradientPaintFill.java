import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

public class GradientPaintFill extends Frame {
    private final int WIDTH = 200;
    private final int HEIGHT = 200;
    public GradientPaintFill(String title)
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
        Ellipse2D e = new Ellipse2D.Float(40, 40, 120, 120);
        GradientPaint gp = new GradientPaint(75, 75, Color.WHITE,
            95, 95, Color.GRAY, true);
        g2.setPaint(gp);
        g2.fill(e);
    }

    public static void main(String[] args)
    {
        new GradientPaintFill("GradientPaintFill");
    }
}
