package obliczenia;

public abstract class Wyrazenie implements Obliczalny {
    public static double suma(Wyrazenie... wyr) {
        double wynik = 0;

        for(Wyrazenie i : wyr) {
            wynik += i.oblicz();
        }
        return wynik;
    }

    public static double iloczyn(Wyrazenie... wyr) {
        double wynik = 0;

        for(Wyrazenie i : wyr) {
            wynik *= i.oblicz();
        }
        return wynik;
    }
}
