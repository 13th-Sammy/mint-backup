import java.util.Scanner;

public class JavaRandom
{
    public static void main(String[] args) 
    {
        int randomNumber = (int)(Math.random() * 100);
        Scanner scan = new Scanner(System.in);
        while (true)
        {
            System.out.println("Guess Number");
            int input = scan.nextInt();
            if (input > randomNumber)
                System.out.println("Too High");
            else if (input < randomNumber)
                System.out.println("Too Low");
            else
            {   
                System.out.println("Correct Guess");
                break;
            }
        }
        scan.close();
    }
}