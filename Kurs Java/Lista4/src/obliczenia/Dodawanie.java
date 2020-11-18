package obliczenia;

public class Dodawanie extends Operator2Arg {

    public Dodawanie(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return arg.oblicz() + arg2.oblicz();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Dodawanie)) return false;

        return this.arg.equals(((Dodawanie) obj).arg) && this.arg2.equals(((Dodawanie) obj).arg2);
    }

    @Override
    public String toString() {
        return "("+arg.toString() + "+" + arg2.toString()+")";
    }

}
