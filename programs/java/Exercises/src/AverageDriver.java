public class AverageDriver {
    public static void main(String[] args) {
        Average average = new Average(new int[50]);
        average.fillArray(2, 4);
        System.out.println(average.text());
        System.out.println("Sum: " + average.sum());
        System.out.println("Avg: " + (average.sum()/(double)average.arr.length));
        double val = 0;
        for (int i = 0; i < 20; i++) val += average.threenumavg();
        System.out.println("Avg 3 nums 20 times: " + (val / 20));
    }
}
