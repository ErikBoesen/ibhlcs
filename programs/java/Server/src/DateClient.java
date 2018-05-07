import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.Socket;

public class DateClient {
    public static void main(String[] args) throws IOException {
        JOptionPane.showMessageDialog(null, "My IP Address is " + InetAddress.getLocalHost().getHostAddress());
        String serverAddress = JOptionPane.showInputDialog("Enter IP address of a machine that is running the date service on port 9090: ");
        Socket s = new Socket(serverAddress, 9876);
        BufferedReader input = new BufferedReader(new InputStreamReader(s.getInputStream()));
        String answer =  input.readLine();
        JOptionPane.showMessageDialog(null, answer);
        System.exit(0);
    }
}
