import java.io.*;
import java.util.*;

class RemoveElementsFromHashMap
{
    public static void main(String[] args)
    {
        Map<Integer, String> hm = new HashMap<>();

        hm.put(1, "Geeks");
        hm.put(2, "For");
        hm.put(3, "Geeks");
        hm.put(4, "For");

        System.out.println("Old Map: " + hm);
        hm.remove(4); // use a key to remove
        System.out.println("New Map: " + hm);
        hm.remove(0); // Remove that which does not exist
        System.out.println("New Map: " + hm); 

        hm.clear(); // remove everything
        System.out.println("New Map: " + hm);
    }
}
