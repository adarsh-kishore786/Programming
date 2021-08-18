import java.io.*;
import java.util.*;

class AddElementsToHashMap
{
    public static void main(String[] args)
    {
        HashMap<Integer, String> hm1 = new HashMap<>();

        hm1.put(1, "Geeks");
        hm1.put(2, "for");
        hm1.put(3, "Gee");

        System.out.println("Initially, hm1 = " + hm1);
        hm1.put(3, "Geeks");
        System.out.println("Now, hm1 = " + hm1);
        System.out.println("hm1.containsValue(\"Geeks\"): " + hm1.containsValue("Geeks"));
    }
}
