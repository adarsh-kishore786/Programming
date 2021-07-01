import java.awt.*;
import java.awt.font.TextAttribute;
import java.awt.geom.AffineTransform;
import java.util.Hashtable;;

public class FontDerivation extends ApplicationFrame 
{
    public static void main(String[] args) {
        FontDerivation f = new FontDerivation();
        f.setTitle("Font Derivation");
        f.setSize(500, 200);
        f.center();
        f.setVisible(true);
    }    

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,   
                    RenderingHints.VALUE_ANTIALIAS_ON);

        Font font = new Font("Serif", Font.PLAIN, 1);
        float x = 20, y = 20;

        Font font24 = font.deriveFont(24.0f);
        g2.setFont(font24);
        g2.drawString("font.derive(24.0f)", x, y += 30);

        Font font24italic = font24.deriveFont(Font.ITALIC);
        g2.setFont(font24italic);
        g2.drawString("font24.derive(Font.ITALIC)", x, y += 30);

        AffineTransform at = AffineTransform.getShearInstance(0.2, 0);
        Font font24shear = font24.deriveFont(at);
        g2.setFont(font24shear);
        g2.drawString("font24.deriveFont(at)", x, y += 30);

        Hashtable<TextAttribute, Float> attributes = new Hashtable<>();
        attributes.put(TextAttribute.WEIGHT, TextAttribute.WEIGHT_BOLD);
        Font font24bold = font24.deriveFont(attributes);

        g2.setFont(font24bold);
        g2.drawString("font24.deriveFont(attributes)", x, y += 30);
    }
}
