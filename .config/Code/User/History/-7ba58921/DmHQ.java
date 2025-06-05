import java.util.Scanner;

public class Main 
{
    public static void main()
    {
        Scanner scan = new Scanner(System.in);
        boolean loop = true;
        while(loop == true)
        {
            System.out.println("Enter 1 to add book\nEnter 2 to see all books\nEnter 3 to quit");
            int choice = scan.nextInt();
            switch (choice)
            {
                case 1 ->
                {                    
                    System.out.println("Enter book name");
                    String name = scan.nextLine();
                    System.out.println("Enter author name");
                    String author = scan.nextLine();
                    System.out.println("Enter publication year");
                    int year = scan.nextInt();
                    Book ob = new Book(name, author, year);
                }
                case 2 ->
                {
                    ;
                }
                case 3 ->
                    loop = false;
                default ->
                    System.out.println("Wrong Choice");
            }
        }
        scan.close();
    }   
}