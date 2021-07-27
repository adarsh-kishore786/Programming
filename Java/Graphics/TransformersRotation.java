import java.awt.*;
import java.awt.geom.AffineTransform; 

public class TransformersRotation extends Transformers
{
    public static void main(String[] args) {
        Transformers t = new TransformersRotation();
        Frame f = t.getFrame();
        f.setVisible(true);
    }

    public AffineTransform getTransform()
    {
        AffineTransform at = AffineTransform.getTranslateInstance(150, 0);
        at.rotate(-Math.PI / 6, 0, 0);
        return at;
    }
}
