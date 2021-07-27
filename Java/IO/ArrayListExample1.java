import java.util.*;

public class ArrayListExample1 {
    public static void main(String[] args) 
    {
        ArrayList<String> list = new ArrayList<>();
        list.add("Mango");
        list.add("Apple");
        list.add("Banana");
        list.add("Grapes");
        
        for (String fruit : list)
            System.out.println(fruit);
    }
}