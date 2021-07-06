import java.io.*;

public class DataStreams 
{
    static final String dataFile = "invoicedata.dat";
    
    static final double[] prices = { 19.99, 9.99, 15.99, 3.99, 4.99 };
    static final int[] units = { 12, 8, 13, 29, 50 };
    static final String[] descs = 
    {
        "Java T-Shirt",
        "Java Mug",
        "Duke Juggling Dolls", 
        "Java Pin",
        "Java Key Chain"
    };

    static void save()
    {
        DataOutputStream out = null;
        try
        {
            out = new DataOutputStream(new FileOutputStream(dataFile));
            for (int i = 0; i < prices.length; i++)
            {
                out.writeDouble(prices[i]);
                out.writeInt(units[i]);
                out.writeUTF(descs[i]);   
            }
        }
        catch (FileNotFoundException fnfe) { System.err.println(fnfe); }
        catch (IOException ie) { System.err.println(ie); }
        finally 
        {
            if (out != null) 
            try { out.close(); }
            catch (IOException ie) { System.err.println(ie); }
        }
    }

    static void read()
    {
        DataInputStream in = null;

        double price;
        int unit;
        String desc;
        double total = 0.0;

        try
        {
            in = new DataInputStream(new FileInputStream(dataFile));

            try
            {
                while (true)
                {
                    price = in.readDouble();
                    unit = in.readInt();
                    desc = in.readUTF();
                    System.out.format("You ordered %d units of %s at" + 
                        " %.2f%n", unit, desc, price);

                    total += unit * price;
                }
            }
            catch (EOFException eof) 
            {
                System.out.format("Total price: %.2f%n", total);
            }
        }
        catch (FileNotFoundException fnfe) { System.err.println(fnfe); }
        catch (IOException ie) { System.err.println(ie); }
        finally 
        {
            if (in != null)
            {
                try { in.close(); }
                catch (IOException ie) { System.err.println(ie); }
            }
        }
    }

    public static void main(String[] args) 
    {
        read();
    }
}
