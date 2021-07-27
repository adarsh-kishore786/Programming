import java.awt.*;
import java.awt.geom.*;

public class Clipping extends ApplicationFrame {
    public static void main(String[] args) {
        Clipping f = new Clipping();
        f.setTitle("Clipping");
        f.setSize(300, 200);
        f.center();
        f.setVisible(true);
    }

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;
        Rectangle2D rect = new Rectangle2D.Double(0, 0, 300, 200);
        Area s = new Area(rect);

        GeneralPath path = new GeneralPath(GeneralPath.WIND_EVEN_ODD);
        path.moveTo(50, 50);
        path.lineTo(70, 44);
        path.curveTo(100, 10, 140, 80, 160, 80);
        path.lineTo(190, 40);
        path.lineTo(200, 56);
        path.quadTo(100, 150, 70, 60);
        path.closePath();

        Ellipse2D ellipse = new Ellipse2D.Double(75, 75, 30, 20);
        Area a1 = new Area(path);
        Area a2 = new Area(ellipse);
        a1.add(a2);
        s.subtract(a1);

        g2.clip(s);
        Rectangle2D r = new Rectangle2D.Double(50, 50, 200, 100);
        g2.fill(r);
    }
}
