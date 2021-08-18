import java.util.*;

public class RemoveElementArrayList
{
    public static void main(String[] args)
    {
        List<String> arr1 = new ArrayList<>();

        arr1.add("Hello");
        arr1.add("Hi");
        arr1.add("Bye");

        System.out.println("Initially, List: " + arr1);
        arr1.remove("Hi");
        System.out.println("Finally, List: " + arr1);

        // Removing an element which does not exist
        arr1.remove("This does not exist");
        System.out.println("List: " + arr1);
    }
}
