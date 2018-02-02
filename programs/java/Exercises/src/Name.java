public class Name {
    public int rank;
    public int occurrences;

    public Name(int rank, int occurrences) {
        this.rank = rank;
        this.occurrences = occurrences;
    }
    public String toString() {
        return "Rank #" + this.rank + " with " + this.occurrences + " occurrences";
    }
}
