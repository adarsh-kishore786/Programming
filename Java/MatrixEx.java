public class MatrixEx 
{
    public static void print(double[][] m)
    {
        for (double[] row : m)
        {
            for (double e : row)
                System.out.print(String.format("%5.2f ", e));
            System.out.println();
        }
        System.out.println();
    }

    public static void print(double[] v)
    {
        System.out.print("[ ");
        for (double e : v)
            System.out.print(e + " ");
        System.out.println("]\n");
    }
    public static void main(String[] args) 
    {
        double[][] A = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("A = ");
        print(A);

        System.out.println("A.T = ");
        print(Matrix.transpose(A));

        double[] v = {1, 2, 3};
        System.out.print("v = ");
        print(v);

        double[] v1 = Matrix.multiply(A, v);
        System.out.print("Av = ");
        print(v1);

        double[] v2 = Matrix.multiply(v, A);
        System.out.print("vA = ");
        print(v2);
    }    
}
