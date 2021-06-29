import java.awt.*;

public class SimpleText extends ApplicationFrame 
{
    public static void main(String[] args) 
    {
        SimpleText f = new SimpleText();
        f.setTitle("Simple Text");
        f.setSize(300, 200);
        f.center();
        f.setVisible(true);
    }

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                    RenderingHints.VALUE_ANTIALIAS_ON);

        Font font = new Font("Serif", Font.PLAIN, 96);
        g2.setFont(font);

        g2.drawString("jade", 40, 120);
    }
}
