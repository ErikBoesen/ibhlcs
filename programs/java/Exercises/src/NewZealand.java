import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class NewZealand {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("new_zealand.txt"));
        int[] years = new int[5];
        sc.next();
        HashMap<String, Name>[] data = new HashMap[5];
        for (int i = 0; i < years.length; i++) {
            years[i] = sc.nextInt();
            data[i] = new HashMap<>();
        }
        int rank, occurrences;
        String name;
        while (sc.hasNextLine()) {
            rank = sc.nextInt();
            for (int i = 0; i < years.length; i++) {
                name = sc.next();
                occurrences = sc.nextInt();
                data[i].put(name, new Name(rank, occurrences));
            }
        }

        Scanner kb = new Scanner(System.in);
        System.out.print("State a name: ");
        String in = kb.next();
        for (int i = 0; i < years.length; i++)
            System.out.println(years[i] + " | " + (data[i].containsKey(in) ? data[i].get(in).toString() : "No appearance"));
    }
}
