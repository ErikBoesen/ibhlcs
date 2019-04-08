public class Book {
    private double fine;
    private boolean availability;

    public Book(double fine, boolean availability) {
        this.setFine(fine);
        this.setAvailability(availability);
    }

    public double getFine() { return this.fine; }
    public void setFine(double fine) { this.fine = fine; }
    public boolean getAvailability() { return this.availability; }
    public void setAvailability(boolean availability) { this.availability = availability; }
}
