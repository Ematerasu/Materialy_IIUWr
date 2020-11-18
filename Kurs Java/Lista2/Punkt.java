public class Punkt {
    private double x,y;

    public Punkt(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double get_x() {
        return x;
    }

    public double get_y() {
        return y;
    }

    public void Przesun(Wektor v) {
        this.x += v.dx;
        this.y += v.dy;
    }

    public void Obrot(Punkt p, double kat) {
        this.x = p.get_x() + (this.x - p.get_x())*Math.cos(kat) - (this.y - p.get_y())*Math.sin(kat);
        this.y = p.get_y() + (this.x - p.get_x())*Math.sin(kat) + (this.y - p.get_y())*Math.cos(kat);
    }

    public void Odbij(Prosta p) {
        this.x = ((1-p.a*p.a)/(1+p.a*p.a)) * this.x + (2*p.a/(1+p.a*p.a))*this.y;
        this.y = (2*p.a/(1+p.a*p.a))*x - ((1-p.a*p.a)/(1+p.a*p.a)) * this.y + p.c;
    }
    

}