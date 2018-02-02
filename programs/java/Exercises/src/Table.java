public class Table {
    String material;
    int legs;
    String color;

    public Table() {
        material = "wood";
        legs = 1;
        color = "black";
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public String getMaterial() {
        return this.material;
    }
}
