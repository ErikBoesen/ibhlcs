public class StatisticsDriver {
    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 1, 7};
        Statistics st = new Statistics(arr);
        System.out.println("Min: " + st.getMin());
        System.out.println("Max: " + st.getMax());
        System.out.println("Mean: " + st.getMean());
        System.out.println("Median: " + st.getMedian());
        System.out.println("Mode: " + st.getMode());
        double[] q = st.getQuartiles();
        System.out.println("Quartiles: " + q[0] + " " + q[1] + " " + q[2]);
        System.out.println("SD: " + st.getSD());
    }
}
