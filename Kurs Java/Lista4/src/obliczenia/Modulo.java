package obliczenia;

public class Modulo extends Operator2Arg {

    public Modulo(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return arg.oblicz() % arg2.oblicz();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Modulo)) return false;

        return this.arg.equals(((Modulo) obj).arg) && this.arg2.equals(((Modulo) obj).arg2);
    }

    @Override
    public String toString() {
        return arg.toString() + " mod " + arg2.toString();
    }

}
