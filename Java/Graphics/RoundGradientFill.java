import java.awt.*;
import java.awt.geom.*;

public class RoundGradientFill extends ApplicationFrame 
{
    public static void main(String[] args) 
    {
        RoundGradientFill f = new RoundGradientFill();
        f.setTitle("RoundGradientPaint");
        f.setSize(200, 200);
        f.center();
        f.setVisible(true);    
    }    

    public void paint(Graphics g) 
    {
        Graphics2D g2 = (Graphics2D) g;
        RoundRectangle2D r = new RoundRectangle2D.Float(25, 35,
                            150, 150, 25, 25);
        RoundGradientPaint rgp = new RoundGradientPaint(75, 75, 
                            Color.MAGENTA, new Point2D.Double(0, 85), Color.BLUE);
        g2.setPaint(rgp);
        g2.fill(r);
    }
}
