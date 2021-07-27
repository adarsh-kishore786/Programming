public class Car
{
    private String model;

    public Car(String model)
    {
        this.model = model;
    }

    public static void swap(Car c1, Car c2)
    {
        String temp = c1.model;
        c1.model = c2.model;
        c2.model = temp;
    }

    public String getModel()
    {
        return model;
    }

    public String toString()
    {
        return "Model " + model;
    }

    public static void main(String[] args)
    {
        Car c1 = new Car("45T");
        Car c2 = new Car("90F");

        System.out.println("Before swapping, c1 = " + c1 + ", c2 = " + c2);
        Car.swap(c1, c2);
        System.out.println("After swapping, c2 = " + c1 + ", c2 = " + c2);
    }
}