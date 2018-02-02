import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Board extends Applet implements Runnable, KeyListener
{
    Snake snake = new Snake(1, 1);
    Apple apple = new Apple();
    final int SQSIZE = 20, HW = 30;

    public void init() {
        setSize(this.SQSIZE * this.HW, this.SQSIZE * this.HW);
        setBackground(Color.WHITE);
        addKeyListener(this);
        setFocusable(true);

        apple.replace(this.HW);
    }
    public void start() {
        Thread th = new Thread(this);
        th.start();
    }
    public void stop() {}
    public void paint(Graphics g) {
        g.setColor(Color.GREEN);
        for (int i = 0; i < this.snake.seg.size(); i++) g.fillRect(this.snake.seg.get(i).x * this.SQSIZE, this.snake.seg.get(i).y * this.SQSIZE, this.SQSIZE, this.SQSIZE);
        g.setColor(Color.RED);
        g.fillRect(apple.x * this.SQSIZE, apple.y * this.SQSIZE, this.SQSIZE, this.SQSIZE);
    }
    public void run() {
        Thread.currentThread().setPriority(Thread.MIN_PRIORITY);
        while(true) {
            this.snake.move();

            if (snake.ate(apple)) {
                apple.replace(this.HW);
                this.snake.grow();
            }
            if (snake.wall(this.HW)) {
                System.out.println(this.snake.seg.size());
                this.snake.seg.clear();
                this.snake.seg.add(new Segment(1, 1));
                this.snake.setSpeed(0, 0);
                this.apple.replace(this.HW);
                //System.exit(0);
            }

            repaint();
            try { Thread.sleep(100); } catch(InterruptedException e) {}
        }
    }
    public void keyTyped(KeyEvent e) {}
    public void keyPressed(KeyEvent e) {
        int k = e.getKeyCode();
        if (k >= 37 && k <= 40) this.snake.setSpeed((k&1)!=0 ? k-38 : 0, (k&1)!=0 ? 0 : k-39);
    }
    public void keyReleased(KeyEvent e) {}
}