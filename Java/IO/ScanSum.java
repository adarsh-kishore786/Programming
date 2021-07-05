import java.io.*;
import java.util.*;

public class ScanSum 
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = null;
        double sum = 0;
        
        try 
        {
            sc = new Scanner(new BufferedReader(new FileReader("usnumbers.txt")));
            sc.useLocale(Locale.US);

            while (sc.hasNext())
            {
                if (sc.hasNextDouble())
                    sum += sc.nextDouble();
                else
                    sc.next();
            }
        }
        finally 
        {
            sc.close();
        }
        System.out.println(sum);
    }    
}
