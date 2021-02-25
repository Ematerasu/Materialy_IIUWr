package Labirynt;

import java.util.Collections;
import java.util.Arrays;

public class Maze {

    private int size;
    private Chamber[][] chambers;

    public Maze(int size, Chamber[][] chambers) {
        this.size = size;
        this.chambers = chambers;
        InitiateChambers();
        GenerateMaze(0, 0);
    }

    private void InitiateChambers() {
        for(int i = 0; i<size; i++){
            for(int j = 0; j<size; j++) {
                chambers[i][j] = new Chamber();

                if(i == 0) {
                    chambers[i][j].N.BuildWall();
                }

                if(j == 0) {
                    chambers[i][j].W.BuildWall();
                }

                if(i == size-1) {
                    chambers[i][j].S.BuildWall();
                }

                if(j == size - 1) {
                    chambers[i][j].E.BuildWall();
                }
            }
        }
        chambers[0][0].SetEndChamber(true);
        chambers[0][0].SetVisited(true);
    }
    private enum Direction {
        N(-1, 0), S(1, 0), E(0, 1), W(0, -1);
        private final int dx;
        private final int dy;

        Direction(int dx, int dy) {
            this.dx = dx;
            this.dy = dy;
        }
    }


    private void GenerateMaze(int cx, int cy) {
        Direction [] dirs = Direction.values();
        Collections.shuffle(Arrays.asList(dirs));
        for (Direction dir : dirs) {
            int nx = cx + dir.dx;
            int ny = cy + dir.dy;
            if ((nx >= 0) && (nx < size) && (ny >= 0) && (ny < size) && (chambers[nx][ny].IsVisited() == false)) {
                chambers[nx][ny].SetVisited(true);
                if (dir==Direction.N) chambers[cx][cy].N.BuildWall();
                if (dir==Direction.S) chambers[cx][cy].S.BuildWall();
                if (dir==Direction.E) chambers[cx][cy].E.BuildWall();
                if (dir==Direction.W) chambers[cx][cy].W.BuildWall();
                GenerateMaze(nx, ny);
            }
        }
    }


}
