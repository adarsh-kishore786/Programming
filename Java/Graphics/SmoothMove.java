import java.awt.*;
import java.awt.event.*;

public class SmoothMove extends ApplicationFrame implements MouseMotionListener 
{
    public static void main(String[] args) 
    {
        new SmoothMove();    
    }    

    private int mX, mY;
    private Image mImage;

    public SmoothMove()
    {
        super("Smooth Move");
        setSize(200, 200);
        center();
        addMouseMotionListener(this);
        setVisible(true);   
    }

    public void mouseMoved(MouseEvent me)
    {
        mX = (int)me.getPoint().getX();
        mY = (int)me.getPoint().getY();
        repaint();
    }

    public void mouseDragged(MouseEvent me) { mouseMoved(me); }

    @Override
    public void update(Graphics g) { paint(g); }

    public void paint(Graphics g)
    {
        Dimension d = getSize();
        checkOffscreenImage();

        Graphics offG = mImage.getGraphics();
        offG.setColor(getBackground());
        offG.fillRect(0, 0, d.width, d.height);

        paintOffscreen(mImage.getGraphics());

        g.drawImage(mImage, 0, 0, null);
    }

    private void checkOffscreenImage()
    {
        Dimension d = getSize();
        if (mImage == null || mImage.getWidth(null) != d.width ||
            mImage.getHeight(null) != d.height)
            mImage = createImage(d.width, d.height);
    }

    public void paintOffscreen(Graphics g)
    {
        int s = 10;
        g.setColor(Color.BLUE);
        g.fillRect(mX - s / 2, mY - s / 2, s, s);
    }
}
