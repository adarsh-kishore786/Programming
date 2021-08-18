import java.util.*;

public class TraversalHashMap
{
    public static void main(String[] args)
    {
        Map<String, Integer> map = new HashMap<>();

        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);

        for (Map.Entry<String, Integer> e : map.entrySet())
        {
            System.out.println("Key  : " + e.getKey());
            System.out.println("Value: " + e.getValue());
            System.out.println();
        }

        String[] keys = { "one", "two", "three" };
        for (String key : keys)
        {
            System.out.println("Key  : " + key);
            System.out.println("Value: " + map.get(key));
            System.out.println();
        }
        System.out.println(map.values());
    }
}
