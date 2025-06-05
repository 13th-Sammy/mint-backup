import java.util.ArrayList;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        ArrayList<Book> arr = new ArrayList<>();
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
                    scan.nextLine(); String name = scan.nextLine();
                    System.out.println("Enter author name");
                    String author = scan.nextLine();
                    System.out.println("Enter publication year");
                    int year = scan.nextInt();
                    arr.add(new Book(name, author, year));
                }
                case 2 ->
                {
                    for (int i = 0; i < arr.size(); i++)
                    {
                        System.out.println("Name - " + arr.get(i).bookName);
                        System.out.println("Author - " + arr.get(i).bookAuthor);
                        System.out.println("Publication year - " + arr.get(i).pubYear); 
                        System.out.println();
                    }
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