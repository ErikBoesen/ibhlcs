import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class DateServer {
    public static void main(String[] args) throws java.io.IOException {
        ServerSocket listener = new ServerSocket(9876);
        try {
            while (true) {
                Socket socket = listener.accept();
                try {
                    PrintWriter out = new PrintWriter(socket.getOutputStream());
                    out.println(new Date().toString());
                } catch(Exception ex) {}
                finally {
                    socket.close();
                }
            }
        } catch (Exception ex) {}
    }
}
