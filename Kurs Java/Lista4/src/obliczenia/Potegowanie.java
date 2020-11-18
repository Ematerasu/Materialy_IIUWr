package obliczenia;

public class Potegowanie extends Operator2Arg{

    public Potegowanie(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return Math.pow(arg.oblicz(), arg2.oblicz());
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Potegowanie)) return false;

        return this.arg.equals(((Potegowanie) obj).arg) && this.arg2.equals(((Potegowanie) obj).arg2);
    }

    @Override
    public String toString() {
        return arg.toString() + "^" + arg2.toString();
    }

}
