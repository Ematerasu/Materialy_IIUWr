package obliczenia;

public class Silnia extends Operator1Arg {

    public Silnia(int n) {
        if(n<0){
            throw new IllegalArgumentException("Silnia dziala tylko dla liczb naturalnych");
        }
        this.arg = new Liczba((double)n);
    }

    public double oblicz() {
        double wynik = 1;
        for(double i = arg.oblicz(); i > 0; i-=1){
            wynik *= i;
        }
        return wynik;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Silnia)) return false;

        return this.arg.equals(((Silnia) obj).arg);
    }

    @Override
    public String toString() {
        return "("+arg.toString() + ")!";
    }
}
