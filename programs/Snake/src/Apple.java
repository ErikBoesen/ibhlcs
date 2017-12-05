public class Apple {
    public int x, y;

    public void replace(int hw) {
        this.x = (int)(Math.random() * hw);
        this.y = (int)(Math.random() * hw);
    }
}