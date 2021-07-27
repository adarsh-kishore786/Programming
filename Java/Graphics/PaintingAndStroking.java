import java.awt.*;
import java.awt.geom.*;

public class PaintingAndStroking extends ApplicationFrame   
{
    public static void main(String[] args) {
        PaintingAndStroking f = new PaintingAndStroking();
        f.setTitle("Painting and Stroking");
        f.setSize(300, 150);
        f.center();
        f.setVisible(true);
    }

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;
        double x = 15, y = 50, w = 70, h = 70;

        Ellipse2D e = new Ellipse2D.Double(x, y, w, h);
        GradientPaint gp = new GradientPaint(75, 75, Color.WHITE,
            95, 95, Color.GRAY, true);
        
        g2.setPaint(gp);
        g2.fill(e);

        e.setFrame(x + 100, y, w, h);
        g2.setPaint(Color.BLACK);
        g2.setStroke(new BasicStroke(8));
        g2.draw(e);

        e.setFrame(x + 200, y, w, h);
        g2.setPaint(gp); 
        g2.draw(e);
    }
}
