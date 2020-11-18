public class Wektor {
    public final double dx, dy;

    public Wektor(double x, double y) {
        dx = x;
        dy = y;
    }

    public static Wektor skladanieWektora(Wektor a, Wektor b) {
        return new Wektor(a.dx + b.dx, a.dy + b.dy);
    }

}