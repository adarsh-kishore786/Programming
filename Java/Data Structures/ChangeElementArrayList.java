import java.util.*;

public class ChangeElementArrayList
{
    public static void main(String[] args)
    {
        List<String> arr = new ArrayList<>();

        arr.add("Theatre");
        arr.add("Don't mention");
        arr.add("MacBeth");

        System.out.println("Old List: " + arr);
        arr.set(2, "The Scottish Play");
        System.out.println("New List: " + arr);
    }
}
