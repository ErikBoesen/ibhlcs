public class Hundred {
    private static final String[] OP = {"", "-", "+"};

    public static void main(String[] args) {
        // 0=none, 1=-, 2=+;
        int[] op = new int[8];
        for (int sol = 0; sol < Math.pow(OP.length, op.length); sol++)
            for (int i = 7; i >= 0; i--) {
                if (op[i] < 2) {
                    op[i]++;
                    if (interp(stringify(op)) == 100) System.out.println(stringify(op));
                    break;
                }
                op[i] = 0;
            }
    }
    private static String stringify(int[] signs) {
        String res = "";
        for (int n = 0; n < 8; n++) res += n+1 + OP[signs[n]];
        res += 9;
        return res;
    }
    private static int interp(String eq) {
        char curop = '+';
        int sum = 0;
        String curnum = "";
        for (int i = 0; i <= eq.length(); i++) {
            char c = (i == eq.length()) ? '+' : eq.charAt(i);
            if (isnum(c)) curnum += c;
            else {
                sum += ((curop == '-') ? -1 : 1) * Integer.parseInt(curnum);
                curop = c;
                curnum = "";
            }
        }
        return sum;
    }
    public static boolean isnum(char c) { return c <= 57 && c >= 48; }
}
