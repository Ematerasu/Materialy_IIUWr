package obliczenia;

public class Odejmowanie extends Operator2Arg{

    public Odejmowanie(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return arg.oblicz() - arg2.oblicz();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Odejmowanie)) return false;

        return this.arg.equals(((Odejmowanie) obj).arg) && this.arg2.equals(((Odejmowanie) obj).arg2);
    }

    @Override
    public String toString() {
        return "("+arg.toString() + "-" + arg2.toString()+")";
    }

}
