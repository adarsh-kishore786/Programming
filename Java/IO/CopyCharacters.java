import java.io.*;

public class CopyCharacters 
{
    public static void main(String[] args) 
    {
        FileReader inputStream = null;
        FileWriter outputStream = null;
        
        try
        {
            inputStream = new FileReader("xanadu.txt");
            outputStream = new FileWriter("characteroutput.txt");

            int c;
            while ((c = inputStream.read()) != -1)
            {
                outputStream.write(c);
            }
        }
        catch (IOException ie) { System.out.println(ie); }
        finally
        {
            if (inputStream != null)
            {
                try { inputStream.close(); }
                catch (IOException ie) { System.out.println(ie); }
            }

            if (outputStream != null)
            {
                try { outputStream.close(); }
                catch (IOException ie) { System.out.println(ie); }
            }
        }
    }
}
