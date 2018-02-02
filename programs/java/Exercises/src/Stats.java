import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Stats {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("stats.txt"));
        String[] headers = sc.nextLine().split("\t");

        HashMap<String, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i < headers.length; i++) {
            //map.put(headers[i], new ArrayList<Integer>());
            System.out.printf("%s\t | ", headers[i]);
        }
        System.out.println();

        int ln = 0;
        while (sc.hasNextLine()) {
            ln++;
            for (int i = 0; i < headers.length; i++) {
                String token = sc.next();
                int tk;
                if (token.charAt(0) == '"') tk = Integer.parseInt(token.replaceAll("[\",]", ""));
                else tk = Integer.parseInt(token);
                System.out.println(tk);
                //map.put(headers[i], map.get(headers[i]).add(tk));
                sc.nextLine();
            }
        }

        System.out.println("Enter a category: ");
        Scanner kb = new Scanner(System.in);
        String cat = kb.nextLine();

        ArrayList<Integer> data = map.get(cat);
        System.out.println("High: " + high(data));
        System.out.println("Low: " + low(data));
        System.out.println("Avg: " + avg(data));
    }
    private static int high(ArrayList<Integer> arr) {
        int high = arr.get(0);
        for (int i = 1; i < arr.size(); i++) if (arr.get(i) > high) high = arr.get(i);
        return high;
    }
    private static int low(ArrayList<Integer> arr) {
        int low = arr.get(0);
        for (int i = 1; i < arr.size(); i++) if (arr.get(i) < low) low = arr.get(i);
        return low;
    }
    private static int avg(ArrayList<Integer> arr) {
        int tot = 0;
        for (int i = 0; i < arr.size(); i++) tot += arr.get(i);
        return tot / arr.size();
    }
}
