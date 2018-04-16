package src;

public class School {
    String address;
    int population;

    public School() {

    }
    public School(String address, int population) {
        this.address = address;
        this.population = population;
    }

    public String toString() {
        return "This school is at " + this.address + ", has " + this.population + " students";
    }

    public String getAddress() {
        return this.address;
    }
    public int getPopulation() {
        return this.population;
    }
    private void setAddress(String address) {
        this.address = address;
    }
    private void setPopulation(int population) {
        this.population = population;
    }
}