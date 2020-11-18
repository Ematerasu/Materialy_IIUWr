public class Trojkat {
    private Punkt a, b, c;

    public Trojkat(Punkt a, Punkt b, Punkt c) {

        if(Odcinek.dlugoscOdcinka(a, b) + Odcinek.dlugoscOdcinka(a, c) > Odcinek.dlugoscOdcinka(c, b) && Odcinek.dlugoscOdcinka(c, b) + Odcinek.dlugoscOdcinka(a, c) > Odcinek.dlugoscOdcinka(a, b) && Odcinek.dlugoscOdcinka(c, b) + Odcinek.dlugoscOdcinka(a, b) > Odcinek.dlugoscOdcinka(a, c)) {
            this.a = a;
            this.b = b;
            this.c = c;
           }
        else {
            throw new ArithmeticException("Z tych punktow nie da sie stworzyc trojkata");
        }
    }

    public void Przesun(Wektor v) {
        this.a.Przesun(v);
        this.b.Przesun(v);
        this.c.Przesun(v);
    }

    public void Obroc(Punkt p, double kat) {
        this.a.Obrot(p, kat);
        this.b.Obrot(p, kat);
        this.c.Obrot(p, kat);
    }

    public void Odbij(Prosta p) {
        this.a.Odbij(p);
        this.b.Odbij(p);
        this.c.Odbij(p);
    }

    @Override
    public String toString(){
        return "Wspolrzedne trojkata: ( (" + a.get_x() + ", " + a.get_y() + "), (" + b.get_x() + ", " + b.get_y() + "), (" + c.get_x() + ", " + c.get_y() + ") )";
    }

}