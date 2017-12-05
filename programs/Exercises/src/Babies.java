import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class Babies {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("TopBabyName2000.txt"));

        HashMap<String, Integer> boys = new HashMap();
        HashMap<String, Integer> girls = new HashMap();
        boolean boy = true;
        while (sc.hasNextLine()) {
            String name = sc.nextLine();
            int occ = Integer.parseInt(sc.nextLine().replaceAll(",", ""));
            if (boy) boys.put(name, occ);
            else girls.put(name, occ);
            boy = !boy;
        }
        Scanner kb = new Scanner(System.in);

        System.out.println("What boy name do you want?");
        System.out.println(boys.get(kb.next()));

        System.out.println("What girl name do you want?");
        System.out.println(girls.get(kb.next()));
    }
}
