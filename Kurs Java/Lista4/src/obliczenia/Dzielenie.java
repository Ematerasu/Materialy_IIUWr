package obliczenia;

public class Dzielenie extends Operator2Arg {

    public Dzielenie(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return arg.oblicz() / arg2.oblicz();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Dzielenie)) return false;

        return this.arg.equals(((Dzielenie) obj).arg) && this.arg2.equals(((Dzielenie) obj).arg2);
    }

    @Override
    public String toString() {
        return "("+arg.toString() + "/" + arg2.toString()+")";
    }

}
