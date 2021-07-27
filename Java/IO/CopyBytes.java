import java.io.*;

public class CopyBytes
{
    public static void main(String[] args) 
    {
        FileInputStream in = null;
        FileOutputStream out = null;
        
        try
        {
            in = new FileInputStream("xanadu.txt");
            out = new FileOutputStream("outagain.txt");
            int c;

            while ((c = in.read()) != -1)
                out.write(c);
        }
        catch (IOException ie)
        {
            System.out.println(ie);
        }
        finally
        {
            if (in != null)
            {
                try 
                {
                    in.close();
                }
                catch (IOException ie)
                {
                    System.out.println(ie);
                }
            }

            if (out != null)
            {
                try
                {
                    out.close();
                }
                catch (IOException ie)
                {
                    System.out.println(ie);
                }
            }
        }
    }
}