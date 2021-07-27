import java.awt.*;
import java.awt.image.BufferedImage;

public class TexturedText extends ApplicationFrame 
{
    public static void main(String[] args) {
        TexturedText f = new TexturedText();
        f.setTitle("Textured Text");
        f.setSize(400, 150);
        f.center();
        f.setVisible(true);
    }    

    public void paint(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
            RenderingHints.VALUE_ANTIALIAS_ON);
        Font font = new Font("Times New Roman", Font.PLAIN, 72);
        g2.setFont(font);

        String s = "Checkmate!";
        float x = 20, y = 100;
        BufferedImage bi = getTextureImage();
        Rectangle r = new Rectangle(0, 0, bi.getWidth(), bi.getHeight());
        TexturePaint tp = new TexturePaint(bi, r);
        g2.setPaint(tp);

        g2.drawString(s, x, y);
    }

    private BufferedImage getTextureImage()
    {
        int size = 8;
        BufferedImage bi = new BufferedImage(size, size, 
            BufferedImage.TYPE_INT_ARGB);

        Graphics2D g2 = bi.createGraphics();
        g2.setPaint(Color.RED);
        g2.fillRect(0, 0, size / 2, size / 2);

        g2.setPaint(Color.YELLOW);
        g2.fillRect(size / 2, 0, size, size / 2);

        g2.setPaint(Color.GREEN);
        g2.fillRect(0, size / 2, size / 2, size);

        g2.setPaint(Color.BLUE);
        g2.fillRect(size / 2, size / 2, size, size);

        return bi;
    }
}
