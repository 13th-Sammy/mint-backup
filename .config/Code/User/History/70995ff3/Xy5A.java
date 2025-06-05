
import java.util.Scanner;
public class JavaCalc 
{

    public int add (int x, int y)
    {
        return x+y;
    }
    public int multiply(int x, int y)
    {
        return x*y;
    }
    public int subtract(int x, int y)
    {
        if (x>y)
            return x-y;
        else 
            return y-x;
    }
    public double divide(int x, int y)
    {
        return (double)x/y;
    }
    public static void main(String[] args) 
    {
        JavaCalc ob = new JavaCalc();
        Scanner input = new Scanner(System.in);
        while(true)
        {
            System.out.println("Enter two numbers");
            int x = input.nextInt(); int y = input.nextInt();
            System.out.println("Enter choice -\n1 for add\n2 for subtract\n3 for multiply\n4 for divide");
            int ch = input.nextInt();
            switch (ch)
            {
                case 1:
                {
                    System.out.println("Sum - " + ob.add(x,y));
                    break;
                }
                case 2:
                {
                    System.out.println("Difference - " + ob.subtract(x,y));
                    break;
                }
                case 3:
                {
                    System.out.println("Product - " + ob.multiply(x,y));
                    break;
                }
                case 4:
                {
                    System.out.println("Quotient - " + ob.divide(x,y));
                    break;
                }
                default:
                    System.out.println("Wrong Choice");
            }
            System.out.println("Enter 0 to close, other to continue");
            int close = input.nextInt();
            if (close == 0)
                break;
        }
        input.close();
    }
}