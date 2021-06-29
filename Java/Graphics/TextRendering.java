import java.awt.*;
import java.awt.geom.*;

public class TextRendering extends ApplicationFrame
{
    public static void main(String[] args) 
    {
        TextRendering f = new TextRendering();
        f.setTitle("Text Rendering");
        f.setSize(500, 500);
        f.center();
        f.setVisible(true);
    }    

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
            RenderingHints.VALUE_ANTIALIAS_ON);

        Dimension d = getSize();
        AffineTransform ct = AffineTransform.getTranslateInstance(
            d.width / 2, d.height * 3 / 4);
        g2.transform(ct);

        String s = "jade";
        Font f = new Font("Serif", Font.PLAIN, 128);
        g2.setFont(f);

        int limit = 6;
        for (int i = 1; i <= limit; i++)
        {
            AffineTransform oldTransform = g2.getTransform();

            float ratio = (float)i / (float)limit;
            g2.transform(AffineTransform.getRotateInstance(
                Math.PI * (ratio - 1.0f)));
            float alpha = (i == limit) ? 1.0f : ratio / 3;
            g2.setComposite(AlphaComposite.getInstance(
                AlphaComposite.SRC_OVER, alpha));
            g2.drawString(s, 0, 0);

            g2.setTransform(oldTransform);
        }
    }
}
