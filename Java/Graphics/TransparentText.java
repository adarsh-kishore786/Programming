import java.awt.*;
import java.awt.geom.*;

public class TransparentText extends ApplicationFrame
{
    public static void main(String[] args) {
        TransparentText f = new TransparentText();
        f.setTitle("Transparent Text");
        f.setSize(400, 200);
        f.center();
        f.setVisible(true);
    }  

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        // int mNumberOfLines = 25;
        // Color[] mColors = { Color.RED, Color.GREEN, Color.BLUE };

        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
                        RenderingHints.VALUE_ANTIALIAS_ON);
                        
        Rectangle2D r = new Rectangle2D.Double(50, 50, 150, 100);
        g2.setPaint(Color.RED);
        g2.fill(r);

        Composite c = AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.4f);
        g2.setComposite(c);

        g2.setPaint(Color.BLUE);
        g2.setFont(new Font("Times New Roman", Font.PLAIN, 27));
        g2.drawString("Composite", 25, 130);
    }
}
