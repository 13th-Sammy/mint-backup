
import java.util.Scanner;
public class Program {
    public static void main(String args[])
    {
        System.out.println("Hello world !");
        int x;
        System.out.println("Enter number");
        Scanner scan = new Scanner(System.in);
        x = toInt(scan);
        System.out.println(x);
    }
}