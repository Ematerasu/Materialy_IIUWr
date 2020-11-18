package obliczenia;

public class Mnozenie extends Operator2Arg {

    public Mnozenie(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return arg.oblicz() * arg2.oblicz();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Mnozenie)) return false;

        return this.arg.equals(((Mnozenie) obj).arg) && this.arg2.equals(((Mnozenie) obj).arg2);
    }

    @Override
    public String toString() {
        return "("+arg.toString() + "*" + arg2.toString()+")";
    }

}
