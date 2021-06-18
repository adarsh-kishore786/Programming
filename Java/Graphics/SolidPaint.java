import java.awt.*;
import java.awt.geom.*;

public class SolidPaint extends ApplicationFrame 
{
    public static void main(String[] args) {
        SolidPaint f = new SolidPaint();
        f.setTitle("Solid Paint");
        f.setSize(200, 200);
        f.center();
        f.setVisible(true);
    }    

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;
        Arc2D pie = new Arc2D.Float(0, 50, 150, 150, -30, 90, Arc2D.PIE);
        g2.setPaint(Color.BLUE);
        g2.fill(pie);
    }
}
