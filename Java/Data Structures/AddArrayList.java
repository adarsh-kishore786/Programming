import java.util.*;

public class AddArrayList
{
    public static void main(String[] args)
    {
        List<String> list = new ArrayList<>();

        list.add("Geeks");
        list.add("Geeks");
        list.add(1, "For"); // Ad at position 1

        System.out.println(list);
    }
}
