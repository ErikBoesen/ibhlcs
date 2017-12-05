import java.util.Scanner;

public class Base {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        System.out.print("State a number: ");
        String x = kb.next();
        int ob;
        if (x.startsWith("0b") || x.matches("^[01]*$")) {
            x = x.substring(2, x.length());
            ob = 2;
        } else if (x.startsWith("0x") || x.matches("^[0-9A-Fa-f]*$")) {
            x = x.substring(2, x.length());
            ob = 16;
        } else if (x.startsWith("0")) {
            ob = 8;
        } else {
            System.out.print("Enter the current base: ");
            ob = kb.nextInt();
        }

        System.out.print("State a base to convert to: ");
        int nb = kb.nextInt();

        System.out.println(Integer.toString(Integer.parseInt(x, ob), nb));
    }
}
