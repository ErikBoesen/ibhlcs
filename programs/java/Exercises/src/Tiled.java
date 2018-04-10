package src;

import java.awt.*;
import java.applet.*;

public class Tiled extends Applet {
    private Image world, mountain;
    private final int WIDTH = 380, HEIGHT = 380;

    public void init() {
        world = getImage(getCodeBase(), "world.jpg");
        mountain = getImage(getCodeBase(), "everest.jpg");
        setSize(WIDTH, HEIGHT);
    }

    public void paint(Graphics g) {
        g.drawImage(world, WIDTH, WIDTH, WIDTH, WIDTH, this);
    }
}
