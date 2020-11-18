package obliczenia;
import struktury.*;

public class DeklaracjaZmiennej extends Instrukcja {

    private String name;

    public DeklaracjaZmiennej(String k) {
        if(k == null) throw new NullPointerException("Nie podano zmiennej ktora nalezy zadeklarowac");
        this.name = k;
    }

    @Override
    public void wykonaj() {
        Zmienna.zbiorZmiennych.Wstaw(new Para(this.name, 0.0));
    }

    @Override
    public String toString() {
        return "var " + this.name+";\n";
    }
}
