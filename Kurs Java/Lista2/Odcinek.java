public class Odcinek {
    private Punkt a, b;

    public Odcinek(Punkt a, Punkt b) {
        if(a.get_x() == b.get_x() && a.get_y() == b.get_y()){
            throw new ArithmeticException("Punkty sa te same");
        } 
        
        this.a = a;
        this.b = b;
    }

    public static double dlugoscOdcinka(Punkt a, Punkt b) {
        return Math.sqrt( (b.get_x()-a.get_x())*(b.get_x()-a.get_x()) + (b.get_y()-a.get_y())*(b.get_y()-a.get_y()) );
    }

    public void Przesun(Wektor v) {
        this.a.Przesun(v);
        this.b.Przesun(v);
    }

    public void Obroc(Punkt p, double kat) {
        a.Obrot(p, kat);
        b.Obrot(p, kat);
    }

    public void Odbij(Prosta p) {
        this.a.Odbij(p);
        this.b.Odbij(p);
    }

    @Override
    public String toString(){
        return "Wspolrzedne odcinka: ( (" + a.get_x() + ", " + a.get_y() + "), (" + b.get_x() + ", " + b.get_y() + ") )";
    }

}