import java.io.*;

public class TextWrite 
{
    public static void main(String[] args) 
    {
        FileOutputStream fout;
        
        try
        {
            fout = new FileOutputStream("myfile.txt");
            new PrintStream(fout).println("hello world!");
            fout.close();
        }
        catch (IOException ie)
        {
            System.out.println("Unable to write to file");
            System.exit(1);
        }
    }
}
