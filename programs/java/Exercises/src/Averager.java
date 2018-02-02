import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Averager {
    public static void main(String[] args) {
        Scanner instream = null;
        try {
            instream = new Scanner(new FileInputStream("numbers.txt"));
        } catch(FileNotFoundException e) {
            System.out.println("The file was not found");
            System.exit(0);
        }
        int counter = 0;
        for (int i = 0; i < 20; i++) {
            counter += instream.nextInt();
        }
        instream.close();
        System.out.println("The average number of rooms is " + counter/20.0);
    }
}
