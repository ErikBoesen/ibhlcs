package src;

public class MiddleSchool extends School {
    private boolean lineUp;
    public MiddleSchool(String address, int population, boolean lineUp) {
        super(address, population);
        this.lineUp = lineUp;
    }
    public String toString() {
        return super.toString() + (this.lineUp ? ", and lines up" : ", and does not line up");
    }
}