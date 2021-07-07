import java.io.*;
import java.math.BigDecimal;
import java.util.Calendar;

public class ObjectStreams 
{
    static final String dataFile = "invoicedata.dat";

    static final BigDecimal[] prices = 
    {
        new BigDecimal("19.99"),
        new BigDecimal("9.99"),
        new BigDecimal("15.99"),
        new BigDecimal("3.99"),
        new BigDecimal("4.99")
    };

    static final int[] units = { 12, 8, 13, 29, 50 };
    static final String[] descs = 
    {
        "Java T-Shirt",
        "Java Mug",
        "Duke Juggling Dolls",
        "Java Pin",
        "Java Key Chain"  
    };

    public static void main(String[] args) 
    {
        readFromFile();
    }

    public static void readToFile()
    {
        ObjectOutputStream out = null;

        try 
        {
            out = new ObjectOutputStream(
                new BufferedOutputStream(new FileOutputStream(dataFile)));

            out.writeObject(Calendar.getInstance());

            for (int i = 0; i < prices.length; i++)
            {
                out.writeObject(prices[i]);
                out.writeInt(units[i]);
                out.writeUTF(descs[i]);
            }
        }
        catch (IOException ie) { System.err.println(ie); }
        finally 
        {
            if (out != null) 
            {
                try { out.close(); }
                catch (IOException ie) { System.err.println(ie); }
            }
        }
    }

    public static void readFromFile()
    {
        ObjectInputStream in = null;

        Calendar date;
        BigDecimal price;
        int unit;
        String desc;
        BigDecimal total = new BigDecimal(0);

        try
        {
            in = new ObjectInputStream(new 
                BufferedInputStream(new FileInputStream(dataFile)));

            date = (Calendar) in.readObject();
            System.out.format("On %tA, %<tB %<te, %<tY:%n", date);

            while (true)
            {
                price = (BigDecimal) in.readObject();
                unit = in.readInt();
                desc = in.readUTF();

                System.out.format("You order %d units of %s at " + 
                    "%.2f%n", unit, desc, price);
                total = total.add(price.multiply(new BigDecimal(unit)));
            }
        }
        catch (EOFException eof) { System.out.format("Total cost: %.2f", total); }
        catch (IOException ie) { System.err.println(ie); }
        catch (ClassNotFoundException cnfe) { System.err.println(cnfe); }
        finally
        {
            if (in != null)
            {
                try { in.close(); }
                catch (IOException ie) { System.err.println(ie); }
            }
        }
    }
}
