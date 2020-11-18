package obliczenia;

public class Maksimum extends Operator2Arg {

    public Maksimum(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        double max = arg.oblicz();
        if(arg2.oblicz() > arg.oblicz()) max = arg2.oblicz();
        return max;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Maksimum)) return false;

        return this.arg.equals(((Maksimum) obj).arg) && this.arg2.equals(((Maksimum) obj).arg2);
    }

    @Override
    public String toString() {
        return "max(" + arg + ", " + arg2 + ")";
    }
}
