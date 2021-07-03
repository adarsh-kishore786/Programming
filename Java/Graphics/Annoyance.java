import java.awt.*;
import java.awt.event.*;

public class Annoyance extends ApplicationFrame implements MouseMotionListener 
{
    public static void main(String[] args) 
    {
        new Annoyance();    
    }    

    private int mX, mY;

    public Annoyance()
    {
        super("Annoyance");
        setSize(200, 200);
        center();
        addMouseMotionListener(this);
        setVisible(true);
    }

    public void mouseMoved(MouseEvent me)
    {
        mX = (int) me.getPoint().getX();
        mY = (int) me.getPoint().getY();

        repaint();
    }

    public void mouseDragged(MouseEvent me) { mouseMoved(me); }

    public void paint(Graphics g)
    {
        int s = 10;
        g.setColor(Color.BLUE);
        g.fillRect(mX - s / 2, mY - s / 2, s, s);
    }   
}
