import java.util.HashMap;
import java.util.Scanner;

public class Library {
    private final Scanner scan=new Scanner(System.in);
    private final HashMap<Long, Book> BookList=new HashMap<>();

    public static void main(String args[]) {
        Library lib=new Library();

        while(true) {
            lib.printMenu();
            int choice=lib.scan.nextInt();
            
            if(choice==0) {
                break;
            }
            else if(choice==1) {
                ;
            }
        }
    }

    private void printMenu() {
        System.out.println("Welcome to the Library Management System !");
        System.out.println("Press 0 - Close");
        System.out.println("Press 1 - View Books");
        System.out.println("Press 2 - Add Book");
        System.out.println("Press 3 - Remove Book");
        System.out.println();
    }

    private void addBook() {
        System.out.println("Enter Book ID -");
        long ID=scan.nextLong();
        scan.nextLine();
        System.out.println("Enter Book Name -");
        String t=scan.nextLine().trim();
        scan.nextLine();
        System.out.println("Enter Author Name");
        String a=scan.nextLine().trim();

        for(Book b:BookList.values()) {
            if(b.getTitle().equalsIgnoreCase(t) && b.getAuthor().equalsIgnoreCase(a) && b.getID()!=ID) {
                System.out.println("Title and Author already exist, added to existing Book ID.");
                b.addTotalCopies(1);
                b.addAvailCopies(1);
                return;
            }
            else if(b.getID()==ID && (!b.getTitle().equalsIgnoreCase(t) || !b.getAuthor().equalsIgnoreCase(a))) {
                System.out.println("Different Books cannot have same Book ID, not added.");
                return;
            }
        }

        Book book=new Book(ID, t, a);
        book.addAvailCopies(1);
        book.addTotalCopies(1);
        BookList.put(book.getID(), book);
    }
}