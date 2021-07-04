import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.net.MalformedURLException;
import java.net.URL;

public class Utilities 
{
    private static final Component sComponent = new Component() {};
    private static final MediaTracker sTracker = new MediaTracker(sComponent);    
    private static int sID = 0;

    public static boolean waitForImage(Image image)
    {
        int id;
        synchronized(sComponent) { id = sID++; }
        sTracker.addImage(image, id);

        try { sTracker.waitForID(id); }
        catch (InterruptedException ie) { return false; }

        if (sTracker.isErrorID(id)) return false;
        return true;
    }

    public static Image blockingLoad(String path)
    {
        try 
        {
            return blockingLoad(new URL(path));
        }
        catch (MalformedURLException me) { return null; }
    }

    private static Image blockingLoad(URL url)
    {
        Image image = Toolkit.getDefaultToolkit().getImage(url);
        if (!waitForImage(image)) return null;
        return image;
    }

    public static BufferedImage makeBufferedImage(Image image)
    {
        return makeBufferedImage(image, BufferedImage.TYPE_INT_RGB);
    }

    public static BufferedImage makeBufferedImage(Image image, int imageType)
    {
        if (!waitForImage(image)) return null;

        BufferedImage bufferedImage = new BufferedImage(
            image.getWidth(null), image.getHeight(null),
            imageType
        );
        Graphics2D g2 = bufferedImage.createGraphics();
        g2.drawImage(image, null, null);
        return bufferedImage;
    }

    public static Frame getNonClearingFrame(String name, Component c)
    {
        final Frame f = new Frame(name) 
        {
            @Override
            public void update(Graphics g) { paint(g); }
        };
        sizeContainerToComponent(f, c);
        centerFrame(f);

        f.setLayout(new BorderLayout());
        f.add(c, BorderLayout.CENTER);
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we)
            {
                f.dispose();
            }
        });
        return f;
    }

    public static void sizeContainerToComponent(Container container, 
        Component component)
    {
        if (!container.isDisplayable()) container.addNotify();
        Insets insets = container.getInsets();
        Dimension size = component.getPreferredSize();

        int width = insets.left + size.width + insets.right;
        int height = insets.top + size.height + insets.bottom;
        container.setSize(width, height);
    }

    public static void centerFrame(Frame f)
    {
        Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
        Dimension d = f.getSize();

        int x = (screen.width - d.width) / 2;
        int y = (screen.height - d.height) / 2;
        f.setLocation(x, y);
    }
}
