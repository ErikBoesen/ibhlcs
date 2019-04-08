public class Average {
    public Book(String title, double fine, boolean availability) {
        this.setTitle(title);
        this.setFine(fine);
        this.setAvailability(availability);
    }
    public Book() {}
    public double getFine() { return this.fine; }
    public void setFine(double fine) { this.fine = fine; }
    public String getTitle() { return this.title; }
    public void setTitle(String title) { this.title = title; }
    public boolean getAvailability() { return this.availability; }
    public void setAvailability(boolean availability) { this.availability = availability; }
}
