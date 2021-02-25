package Labirynt;

public class Chamber {
    public Wall N, W, S, E;
    private boolean endChamber = false;
    private boolean visited = false;

    public Chamber() {
        N = new Wall();
        W = new Wall();
        S = new Wall();
        E = new Wall();
    }

    public boolean IsEndChamber() {
        return endChamber;
    }

    public void SetEndChamber(boolean x) {
        endChamber = x;
    }

    public boolean IsVisited() {
        return visited;
    }

    public void SetVisited(boolean x) {
        visited = x;
    }

}
