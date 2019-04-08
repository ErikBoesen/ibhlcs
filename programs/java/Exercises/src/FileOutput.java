import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;

public class FileOutput {
	public static void main(String[] args) {
		PrintWriter outputStream = null;
		try {
			outputStream = new PrintWriter(new FileOutputStream("FileOne.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
			System.exit(0);
		}
		System.out.println("Writing to file");
		outputStream.println("Miles");
		outputStream.println("Arithmetic and geometric");
		// Easy to forget
		outputStream.close();
		System.out.println("End");
	}
}
