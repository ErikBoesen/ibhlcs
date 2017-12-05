import java.util.Scanner;

public class SameString {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter two sentences:");
        String one = kb.nextLine();
        String two = kb.nextLine();

        System.out.println("\"" + longest(one, two) + "\" is the longest common string between those sentences.");
    }
    public static String longest(String one, String two) {
        String str;
        for (int slen = one.length(); slen > 0; slen--) {
            for (int i = 0; i < one.length() - slen; i++) {
                str = one.substring(i, i + slen);
                if (two.contains(str)) return str;
            }
        }
        return "";


    }
}
