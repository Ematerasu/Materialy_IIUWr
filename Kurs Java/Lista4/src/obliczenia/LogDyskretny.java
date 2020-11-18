package obliczenia;

public class LogDyskretny extends Operator2Arg {

    public LogDyskretny(Wyrazenie arg, Wyrazenie arg2) {
        this.arg = arg;
        this.arg2 = arg2;
    }

    public double oblicz() {
        return Math.log(arg2.oblicz())/Math.log(arg.oblicz());
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof LogDyskretny)) return false;

        return this.arg.equals(((LogDyskretny) obj).arg) && this.arg2.equals(((LogDyskretny) obj).arg2);
    }

    @Override
    public String toString() {
        return "Log(" + arg.toString() + ")" + arg2.toString();
    }

}
