import java.util.Scanner;

public class Main {
    private final Scanner scan=new Scanner(System.in);
    //private final Library lib=new Library();

    public static void main(String args[]) {
        Main obMain=new Main();
        Library lib=new Library;
        OUTER:
        while (true) {
            obMain.printMenu();
            int choice=obMain.scan.nextInt();
            switch (choice) {
                case 0 -> {
                    break OUTER;
                }
                case 1 -> {
                    lib.viewBooks();
                }
                case 2 -> {
                    lib.addBook();
                }
                case 3 -> {
                    lib.removeBook();
                }
                case 4 -> {
                    lib.searchBook();
                }
                default -> {
                    System.out.println("Invalid Choice");
                    System.out.println();
                }
            }
        }
    }

    private void printMenu() {
        System.out.println("Welcome to the Library Management System !");
        System.out.println("Press 0 - Close");
        System.out.println("Press 1 - View Books");
        System.out.println("Press 2 - Add Book");
        System.out.println("Press 3 - Remove Book");
        System.out.println("Press 4 - Search Book");
        System.out.println();
    }
}
