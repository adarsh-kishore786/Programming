import java.io.*;
import java.util.*; 

public class Password   
{
    static HashMap<String, String> loginData = new HashMap<>();
    public static void main(String[] args) throws IOException
    {
        readFromFile();
        // loginData.put("goku", "kakarrot");
        // loginData.put("maths", "beautiful");
        // loginData.put("ash", "ketchum");
        // saveToFile();

        // for (String key : loginData.keySet())
        //     System.out.println(key + ": " + loginData.get(key));
    
        Console c = System.console();
        if (c == null)
        {
            System.err.println("No console");
            System.exit(1);
        }    
        boolean verified = false;
        String login = null;
        String oldPassword = null;

        do
        {
            login = c.readLine("Enter your login: ");
            oldPassword = getString(c.readPassword("Enter your old password: "));

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
            String newPassword1 = getString(c.readPassword("Enter your new password: "));
            String newPassword2 = getString(c.readPassword("Enter your new password again: "));
            noMatch = !newPassword1.equals(newPassword2);

            if (noMatch)
                c.format("Passwords don't match. Please try again.%n");
            else
            {
                change(login, newPassword1);
                c.format("Password for %s has changed.%n", login);
            }
            newPassword1 = "";
            newPassword2 = "";
        } while (noMatch);

        oldPassword = "";
    }

    public static void readFromFile()
    {
        DataInputStream in = null;

        try
        {
            in = new DataInputStream(new FileInputStream("login.dat"));

            try
            {
                while (true)
                {
                    String username = in.readUTF();
                    String password = in.readUTF();
                    loginData.put(username, password);
                }
            }
            catch (EOFException eof) {}
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

    public static void saveToFile()
    {
        DataOutputStream out = null;

        try 
        {
            out = new DataOutputStream(new FileOutputStream("login.dat"));

            for (String key : loginData.keySet())
            {
                out.writeUTF(key);
                out.writeUTF(loginData.get(key));
            }
        }
        catch (FileNotFoundException fnfe) { System.err.println(fnfe); }
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

    public static boolean verify(String login, String password) throws IOException
    {
        for (String key : loginData.keySet())
        {
            if (key.equals(login))
            {
                String pass = loginData.get(key);
                return pass.equals(password);
            }
        }
        return false;
    }

    public static void change(String login, String password) throws IOException
    {
        for (String key : loginData.keySet())
        {
            if (key.equals(login))
            {
                loginData.put(key, password);
                saveToFile();
                break;
            }
        }
    }

    private static String getString(char[] arr)
    {
        String nstr = "";
        for (char c : arr)
            nstr += c + "";
        return nstr;
    }
}
