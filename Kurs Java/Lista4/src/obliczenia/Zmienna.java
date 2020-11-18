package obliczenia;
import struktury.*;

public class Zmienna extends Wyrazenie {
    public static final ZbiorNaTablicyDynamicznej zbiorZmiennych = new ZbiorNaTablicyDynamicznej();
    private String name;

    public Zmienna(String k) {
        name = k;
    }

    public double oblicz() {
        return zbiorZmiennych.Czytaj(name);
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Zmienna)) return false;

        return this.name.equals(((Zmienna) obj).name);
    }

    @Override
    public String toString() {
        return name;
    }
}
