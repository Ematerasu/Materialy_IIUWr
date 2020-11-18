package obliczenia;

public class InstrukcjaPisania extends Instrukcja{

    private Wyrazenie wyr;

    public InstrukcjaPisania(Wyrazenie wyr){
        if(wyr == null) throw new NullPointerException("Nie ma czego wypisac");
        this.wyr = wyr;
    }

    public void wykonaj() {
        System.out.println(wyr.oblicz());
    }

    @Override
    public String toString() {
        return "write "+wyr.toString()+";\n";
    }
}
