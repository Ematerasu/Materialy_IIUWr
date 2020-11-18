package obliczenia;
import struktury.Para;

import java.util.Scanner;
import java.io.IOException;

public class InstrukcjaCzytania extends Instrukcja {
    private Liczba value;
    private String name;

    public InstrukcjaCzytania(String k) throws java.io.IOException {
        if(k == null) throw new NullPointerException("Nie podano zmiennej do ktorej wczytac wartosc");

        this.name = k;
    }

    public void wykonaj() {
        try {
            Scanner scan = new Scanner(System.in);
            value = new Liczba(scan.nextInt());
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        Zmienna.zbiorZmiennych.Ustaw(new Para(name.toString(), value.oblicz()));
    }

    @Override
    public String toString() {
        return "read "+name+";\n";
    }
}
