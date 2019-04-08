import java.util.Scanner;
import java.util.HashMap;

public class BookDriver {
    public static void main(String[] args) {
        HashMap<String, Book> books = new HashMap<>();
        books.put("How to get into MIT", new Book(3.14, true));
        books.put("How to play tennis", new Book(2.13, false));
        books.put("How to win friends and influence people", new Book(4.93, true));
        Scanner kb = new Scanner(System.in);
        System.out.print("Title: ");
        String title = kb.nextLine();
        System.out.print("Fine: ");
        double fine = kb.nextDouble();
        System.out.print("Available? (y/n) ");
        boolean availability = Character.toLowerCase(kb.next().charAt(0)) == 'y';
        books.put(title, new Book(fine, availability));

        String requestedTitle;
        kb.nextLine();
        while (true) {
            System.out.print("What book would you like to check out? ");
            requestedTitle = kb.nextLine();
            if (books.containsKey(requestedTitle)) {
                Book book = books.get(requestedTitle);
                if (book.getAvailability()) System.out.println("That book is available!");
                else System.out.println("That book is currently checked out.");
            } else {
                System.out.println("Sorry, we don't have that book.");
            }
            System.out.println();
        }
    }
}
