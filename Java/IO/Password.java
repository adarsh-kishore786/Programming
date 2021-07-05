import java.io.*;
import java.util.*; 

public class Password   
{
    public static void main(String[] args) throws IOException
    {
        Console c = System.console();
        if (c == null)
        {
            System.err.println("No console");
            System.exit(1);
        }    
        boolean verified = false;
        String login = null;
        char[] oldPassword = null;

        do
        {
            login = c.readLine("Enter your login: ");
            oldPassword = c.readPassword("Enter your old password: ");

            if (!verify(login, oldPassword))
                System.err.println("Invalid username/password. Please try again.");
            else 
            {
                System.out.println("Welcome, logging you in...");
                verified = true;
            }
        } while (!verified);

        boolean noMatch;
        do
        {
            char[] newPassword1 = c.readPassword("Enter your new password: ");
            char[] newPassword2 = c.readPassword("Enter your new password again: ");
            noMatch = !Arrays.equals(newPassword1, newPassword2);

            if (noMatch)
                c.format("Passwords don't match. Please try again.%n");
            else
            {
                change(login, newPassword1);
                c.format("Password for %s has changed.%n", login);
            }
            Arrays.fill(newPassword1, ' ');
            Arrays.fill(newPassword2, ' ');
        } while (noMatch);

        Arrays.fill(oldPassword, ' ');
    }

    public static boolean verify(String login, char[] password) throws IOException
    {
        String nl = "U" + login;
        Scanner sc = null;
        try
        {
            sc = new Scanner(new BufferedReader(new FileReader("login.txt")));
            sc.useDelimiter(";");

            while (sc.hasNext())
            {
                String temp = sc.next();
                if (nl.equals(temp))
                {
                    char[] tempP = sc.next().toCharArray();
                    if (Arrays.equals(password, tempP))
                    {
                        sc.close();
                        return true;
                    }
                }
            }
        }
        finally 
        {
            if (sc != null) { sc.close(); }
        }
        return false;
    }

    public static void change(String login, char[] password) throws IOException
    {
        // String total = "";
        // Scanner sc = null;

        // try
        // {
        //     sc = new Scanner(new BufferedReader(new FileReader("login.txt")));

        //     while (sc.hasNextLine())
        //         total += sc.nextLine();
        // }
        // finally { sc.close(); }
        
        // FileWriter fout = null;
        // try 
        // {
        //     fout = new FileWriter("login.txt");
        // }
    }
}
