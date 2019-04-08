import java.util.Scanner;

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

        while (true) {
            System.out.print("What book would you like to check out?");
            String title = kb.nextLine();
            if (books.containsKey(title)) {
                
            } else {
                System.out.println("Sorry, we don't have that book.");
            }
        }
    }
}
