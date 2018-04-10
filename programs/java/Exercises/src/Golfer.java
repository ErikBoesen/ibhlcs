package src;

import java.util.Arrays;

public class Golfer {
    private String name;
    private double handicap;
    public Golfer() {
        handicap = 15;
        int score;
        String course;
    }
    public Golfer(String x) {
        handicap = 15;
        int score;
        String course;
        name = x;
    }
    public Golfer(int[] scores) {
        Arrays.sort(scores);
        handicap = calculateHandicap(scores);
        int score;
        String course;
    }
    public Golfer(String x, int[] scores) {
        Arrays.sort(scores);
        handicap = calculateHandicap(scores);
        int score;
        String course;
        name = x;
    }
    public String getName() {
        return name;
    }
    private double calculateHandicap(int[] scores) {
        double sum = 0;
        for(int i = 0; i < 10 && i < scores.length; i++) sum += (scores[i] - 72);
        return (sum / (scores.length > 10 ? 10 : scores.length));
    }
    public double getHandicap() {
        return this.handicap;
    }
}