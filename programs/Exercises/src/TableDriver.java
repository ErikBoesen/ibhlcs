import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;

public class TableDriver {
    public static void main(String[] args) {
        Table[] tables = new Table[10];
        for (int i = 0; i < 10; i++) {
            tables[i] = new Table();
        }
        System.out.println(tables[4].material);

        PrintWriter opStream = null;
        try {
            opStream = new PrintWriter(new FileOutputStream("fileone.txt"));
        } catch (FileNotFoundException ex) {}
        opStream.println("Hi");
        opStream.close();
    }
}
