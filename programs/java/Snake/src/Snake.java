import java.util.ArrayList;

public class Snake {
    public ArrayList<Segment> seg = new ArrayList<>();
    int sX, sY;

    public Snake(int x, int y) {
        this.seg.add(new Segment(x, y));
    }
    public void setSpeed(int x, int y) {
        if (!((-x == this.sX) && (-y == this.sY)) || this.seg.size() == 1) {
            this.sX = x;
            this.sY = y;
        }
    }
    public void move() {
        for (int i = this.seg.size() - 1; i > 0; i--) {
            this.seg.get(i).x = this.seg.get(i-1).x;
            this.seg.get(i).y = this.seg.get(i-1).y;
        }
        this.seg.get(0).x += this.sX;
        this.seg.get(0).y += this.sY;
    }
    public void grow() {
        Segment prev = this.seg.get(this.seg.size() - 1);
        this.seg.add(new Segment(prev.x + this.sX, prev.y + this.sY));
    }

    public boolean looped() {
        for (int i = 1; i < this.seg.size(); i++)
            if (this.seg.get(i).x == this.seg.get(0).x && this.seg.get(i).y == this.seg.get(0).y)
                return true;
        return false;
    }
    public boolean ate(Apple apple) {
        return this.seg.get(0).x == apple.x && this.seg.get(0).y == apple.y;
    }
    public boolean wall(int hw) {
        return this.seg.get(0).x < 0 || this.seg.get(0).x > hw || this.seg.get(0).y < 0 || this.seg.get(0).y > hw;
    }
}
