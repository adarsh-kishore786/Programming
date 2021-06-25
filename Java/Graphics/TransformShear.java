import java.awt.*;
import java.awt.geom.AffineTransform;

public class TransformShear extends Transformers
{
    public static void main(String[] args) {
        Transformers t = new TransformShear();
        Frame f = t.getFrame();
        f.setVisible(true);
    }    

    public AffineTransform getTransform()
    {
        AffineTransform at = AffineTransform.getTranslateInstance(150, 0);
        at.shear(-0.5, 0);
        return at;
    }
}
