package Labirynt;

public class Wall {

    private boolean exist;

    public Wall() {
        exist = false;
    }

    public boolean DoesWallExist() {
        return exist;
    }

    public void BuildWall() {
        exist = true;
    }

    public void DestroyWall() {exist = false;}

}
