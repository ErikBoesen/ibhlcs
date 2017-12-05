import java.util.stream.IntStream;

public class Average {
    public int[] arr;

    public Average(int[] arr) {
        this.arr = arr;
    }
    public void fillArray(int low, int high) {
        for (int i = 0; i < 50; i++) {
            arr[i] = (int)(Math.random() * high-1) + low;
        }
    }
    public String text() {
        String str = "[";
        for (int i = 0; i < this.arr.length - 1; i++)
            str += (this.arr[i] + ", ");
        str += this.arr[this.arr.length-1] + "]";
        return str;
    }
    public int sum() {
        return IntStream.of(this.arr).sum();
    }
    public double threenumavg() {
        double val = 0;
        for (int i = 0; i < 3; i++) {
            val += this.arr[(int)(Math.random()*50)];
        }
        return (val / 3.0);
    }
}
