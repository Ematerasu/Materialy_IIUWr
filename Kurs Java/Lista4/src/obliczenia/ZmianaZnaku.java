package obliczenia;

public class ZmianaZnaku extends Operator1Arg {

    public ZmianaZnaku(Wyrazenie wyr) {
        this.arg = wyr;
    }

    public double oblicz() {
        return (-1)*this.arg.oblicz();
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof ZmianaZnaku)) return false;

        return this.arg.equals(((ZmianaZnaku) obj).arg);
    }

    @Override
    public String toString() {
        return "-(" + this.arg.toString() + ")";
    }
}
