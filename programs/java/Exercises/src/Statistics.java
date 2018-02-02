import java.util.HashMap;

public class Statistics {
    public int[] a;

    public Statistics(int[] a) {
        this.a = a;
        this.sort(0, a.length-1);
    }

    public int getSum() {
        int t = 0;
        for (int n : a) t += n;
        return t;
    }
    public int getMin() {
        int m = a[0];
        for (int n : a) if (n < m) m = n;
        return m;
    }
    public int getMax() {
        int m = a[0];
        for (int n : a) if (n > m) m = n;
        return m;
    }
    public double getMean() {
        return (double)this.getSum()/a.length;
    }
    public int getMedian() {
        return a[a.length/2];
    }
    public int getMode() {
        HashMap<Integer, Integer> map = new HashMap();
        int tmp;
        for (int n : a) {
            try {
                tmp = map.get(n);
            } catch (NullPointerException e) {
                tmp = 0;
            }
            map.put(n, tmp + 1);
        }
        int max = 0;
        int num = map.get(a[0]);
        for (int x : map.keySet()) {
            if (map.get(x) > max) {
                max = map.get(x);
                num = x;
            }
        }
        return num;
    }
    public double[] getQuartiles() {
        double[] q = new double[3];
        q[1] = a[a.length/2];
        q[0] = (a[0]+a[a.length/2-1])/2.0;
        q[2] = (a[a.length/2+1]+a[a.length-1])/2.0;
        return q;
    }
    public double getSD() {
        double expected = this.getSum()/this.a.length;
        double variance = 0;
        for(int i = 0; i < this.a.length; ++i) {
            double buffer = this.a[i] - expected;
            variance += buffer * buffer;
        }
        return Math.sqrt(variance);
    }

    public void sort(int left, int right) {
        int i = left, j = right;
        int pivot = a[left + (right - left) / 2];
        int tmp;

        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;
                j--;
            }
        }
        if (left < j) this.sort(left, j);
        if (i < right) this.sort(i, right);
    }
}
