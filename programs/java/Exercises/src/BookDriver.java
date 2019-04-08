public class BookDriver {
    public static void main(String[] args) {
        ArrayList<Book> books = {
            Book("How to get into MIT", 3.14, true),
            Book("How to play tennis", 2.13, false),
            Book("How to win friends and influence people", 4.93, true),
        };
        Scanner kb = new Scanner(System.in);
        System.out.print("Title: ");
        String title = kb.nextLine();
        System.out.print("Fine: ");
        double fine = kb.nextDouble();
        System.out.print("Available? (y/n) ");
        boolean available = (kb.nextLine().charAt(0).toLowerCase() == 'y');
        books.add(Book(title, fine, available));
    }
}
