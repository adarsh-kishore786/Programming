import java.awt.*;
import java.awt.geom.*;

public class XORRectangles extends ApplicationFrame {
    public static void main(String[] args) {
        XORRectangles f = new XORRectangles();
        f.setTitle("XOR Rectangle");
        f.setSize(300, 200);
        f.center();
        f.setVisible(true);
    }

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        g2.setXORMode(Color.WHITE);

        Rectangle2D r = new Rectangle2D.Double(50, 50, 150, 100);
        g2.setPaint(Color.RED);
        g2.fill(r);

        g2.transform(AffineTransform.getTranslateInstance(25, 25));

        g2.setPaint(Color.BLUE);
        g2.fill(r);
    }
}
