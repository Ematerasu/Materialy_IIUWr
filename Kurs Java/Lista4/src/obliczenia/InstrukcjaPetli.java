package obliczenia;

public class InstrukcjaPetli extends Instrukcja{

    private Instrukcja ins;
    private Wyrazenie warunek;

    public InstrukcjaPetli(Wyrazenie warunek, Instrukcja ins) {
        if(ins == null || warunek == null) throw new NullPointerException("Bledne argumenty");
        this.ins = ins;
        this.warunek = warunek;
    }

    public void wykonaj(){
        while(warunek.oblicz() == 1.0) {
            ins.wykonaj();
        }
    }

    @Override
    public String toString() {
        return "while("+warunek.toString()+") "+ins.toString();
    }
}
