import java.util.HashMap;
public class HashM
{
    public static void main(String[] args)
    {
        HashMap<String, Integer> map = new HashMap<>();

        map.put("vishal", 10);
        map.put("sachin", 30);
        map.put("vaibhav", 20);

        System.out.println("Size of map is: " + map.size());
        System.out.println(map);

        if (map.containsKey("vishal"))
        {
            int a = map.get("vishal");
            System.out.println("Value for key \"vishal\" is: " + a);
        }
    }
}
