import java.util.Scanner;

public class MadLibs {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter a noun, verb, and another noun.");
        String n1 = kb.next();
        String v1 = kb.next();
        String n2 = kb.next();
        System.out.println(n1 + " " + v1 + "ed a " + n2);
    }
}
