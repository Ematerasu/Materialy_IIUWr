package obliczenia;


public class Liczba extends Wyrazenie{
    private double value;

    public Liczba(double value) {
        this.value = value;
    }

    public double oblicz() {
        return value;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Liczba)) return false;

        return this.value == ((Liczba) obj).value;
    }

    @Override
    public String toString() {
        return Integer.toString((int)value);
    }
}
