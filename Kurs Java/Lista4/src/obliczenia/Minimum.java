package obliczenia;

public class Minimum extends Operator2Arg{

    public Minimum(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        double min = arg.oblicz();
        if(arg2.oblicz() < arg.oblicz()) min = arg2.oblicz();
        return min;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Minimum)) return false;

        return this.arg.equals(((Minimum) obj).arg) && this.arg2.equals(((Minimum) obj).arg2);
    }

    @Override
    public String toString() {
        return "min(" + arg + ", " + arg2 + ")";
    }

}
