import java.io.*;
import java.util.Scanner;

public class ScanXan 
{
    public static void main(String[] args) throws IOException 
    {
        Scanner sc = null;
        
        try
        {
            sc = new Scanner(new BufferedReader(new FileReader("xanadu.txt")));

            while (sc.hasNext())
                System.out.println(sc.next());
        }
        finally
        {
            if (sc != null) sc.close();
        }
    }    
}   
