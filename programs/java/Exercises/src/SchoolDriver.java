package src;

public class SchoolDriver {
    public static void main(String[] args) {
        School gm = new School("7124 Leesburg Pike, Falls Church, Virginia 22043", 700);
        System.out.printf("The school located at %s has %d students.\n", gm.getAddress(), gm.getPopulation());
        School meh = new MiddleSchool("7154 Leesburg Pike, Falls Church, Virginia 22043", 500, true);
        System.out.println(meh.toString());
    }
}
