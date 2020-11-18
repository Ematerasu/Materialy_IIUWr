package obliczenia;
import struktury.*;

public class InstrukcjaPrzypisania extends Instrukcja{
    private Zmienna name;
    private Wyrazenie value;

    public InstrukcjaPrzypisania(Zmienna k, Wyrazenie value) {
        if(k == null) throw new NullPointerException("Nie podano zmiennej do ktorej przypisac wartosc");

        if(value == null) throw new NullPointerException("Nie podano wartosci ktora przypisac do zmiennej");

        this.name=k;
        this.value=value;
    }

    @Override
    public void wykonaj() {
        Zmienna.zbiorZmiennych.Ustaw(new Para(name.toString(), value.oblicz()));
    }

    @Override
    public String toString() {
        return name.toString()+" = "+value.toString()+";\n";
    }
}
