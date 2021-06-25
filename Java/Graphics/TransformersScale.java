import java.awt.*;
import java.awt.geom.AffineTransform;

public class TransformersScale extends Transformers 
{
    public static void main(String[] args) {
        Transformers t = new TransformersScale();
        Frame f = t.getFrame();
        f.setVisible(true);
    }    

    public AffineTransform getTransform()
    {
        AffineTransform at = AffineTransform.getTranslateInstance(150, 0);
        at.scale(0.5, -2);
        return at;
    }
}
