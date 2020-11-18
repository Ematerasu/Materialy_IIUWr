package obliczenia;

public class Stala extends Wyrazenie{
    private double value;

    public Stala(String k) {
        if(k.equals("pi")) {
            value = 3.141592653589;
        }
        else if(k.equals("e")) {
            value = 2.718281828459;
        }
        else if(k.equals("fi")) {
            value = 1.6180339887;
        }
    }

    public double oblicz() {
        return value;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Stala)) return false;

        return this.value == ((Stala) obj).value;
    }

    @Override
    public String toString() {
        return Double.toString(this.value);
    }
}
