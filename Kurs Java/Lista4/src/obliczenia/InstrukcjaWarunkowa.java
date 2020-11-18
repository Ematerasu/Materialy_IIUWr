package obliczenia;

public class InstrukcjaWarunkowa extends Instrukcja {
    Wyrazenie i;
    Instrukcja t, e;

    public InstrukcjaWarunkowa(Wyrazenie i, Instrukcja t, Instrukcja e) {
        if(i == null || t == null || e == null) throw new NullPointerException("Bledne dane");
        this.i = i;
        this.t = t;
        this.e = e;
    }

    public InstrukcjaWarunkowa(Wyrazenie i, Instrukcja t) {
        if(i == null || t == null) throw new NullPointerException("Bledne dane");
        this.i = i;
        this.t = t;
        this.e = null;
    }

    public void wykonaj(){
        if(i.oblicz()==1.0) {
            t.wykonaj();
        }
        else if(e != null) e.wykonaj();
        else if(e == null) return;
    }

    @Override
    public String toString() {
        if(e!=null) return "if("+i.toString()+") "+t.toString()+"\telse "+e.toString();
        else return "if("+i.toString()+") "+t.toString();
    }
}
