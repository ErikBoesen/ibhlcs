import java.util.ArrayList;
import java.util.Scanner;

public class BookDriver {
    public static void main(String[] args) {
        ArrayList<Book> books = new ArrayList<Book>();
        books.add(new Book("How to get into MIT", 3.14, true));
        books.add(new Book("How to play tennis", 2.13, false));
        books.add(new Book("How to win friends and influence people", 4.93, true));
        Scanner kb = new Scanner(System.in);
        System.out.print("Title: ");
        String title = kb.nextLine();
        System.out.print("Fine: ");
        double fine = kb.nextDouble();
        System.out.print("Available? (y/n) ");
        boolean availability = kb.next().equalsIgnoreCase("y");
        books.add(new Book(title, fine, availability));

        while (true) {
            String 
        }
    }
}
