public class Bitwise {
    public static void main(String[] args) {
        System.out.println("Number is " + (even(5) ? "even" : "odd"));
    }
    public static boolean even(int x) {
        return (x&0x1) == 0;
    }
}
