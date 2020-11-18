package obliczenia;

public class Mniejsze extends Operator2Arg{

    public Mniejsze(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        if(arg.oblicz() < arg2.oblicz())
            return 1.0;
        else return 0.0;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Mniejsze)) return false;

        return this.arg.equals(((Mniejsze) obj).arg) && this.arg2.equals(((Mniejsze) obj).arg2);
    }

    @Override
    public String toString() {
        return arg.toString() + "<" + arg2.toString();
    }
}
