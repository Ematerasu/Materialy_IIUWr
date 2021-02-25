package Samotnik;

public class Peg {
    private boolean isGone;
    public int xCord, yCord;
    private boolean canBePiece;

    public Peg(int x, int y){
        isGone = false;
        canBePiece = true;
        xCord = x;
        yCord = y;
    }

    public void setIsGone(boolean b){
        isGone = b;
    }

    public boolean getIsGone(){
        return isGone;
    }

    public void setIsPiece(boolean b){
        canBePiece = b;
    }

    public boolean getIsPiece(){
        return canBePiece;
    }

    @Override
    public String toString() {
        if(!canBePiece) return "-";
        else if(isGone) return "0";
        else return "1";
    }
}
