package src;

import javax.swing.JOptionPane;
import java.util.Arrays;

public class Golf {
    public static void main(String[] args) {
        Golfer[] golfers = new Golfer[4];
        for (int i = 0; i < golfers.length; i++) {
            golfers[i] = new Golfer(JOptionPane.showInputDialog("Input Golfer #" + i + " Name:"),
                                    Arrays.asList(JOptionPane.showInputDialog("Input Golfer #" + i + " Scores: ").split(","))
                                        .stream().map(String::trim).mapToInt(Integer::parseInt).toArray());
        }
        for (int i = 0; i < golfers.length; i++)
            System.out.println("Golfer #" + i + ": " + golfers[i].getName() + " Handicap: " + golfers[i].getHandicap());
    }
}