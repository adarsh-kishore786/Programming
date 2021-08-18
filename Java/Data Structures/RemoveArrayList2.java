import java.util.*;

public class RemoveArrayList2
{
    public static void main(String[] args)
    {
        List<Integer> arr = new ArrayList<>();

        arr.add(5);
        arr.add(4);
        arr.add(2);
        arr.add(3);
        arr.add(1);

        System.out.println("List: " + arr);
        arr.remove(1); // defaults to position not object
        System.out.println("List: " + arr);
        arr.remove(Integer.valueOf(5));
        System.out.println("List: " + arr);
    }
}
