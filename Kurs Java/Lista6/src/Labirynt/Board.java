package Labirynt;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.imageio.ImageIO;
import java.awt.event.KeyEvent;

public class Board extends Canvas{
    private int size;
    private Chamber[][] chambers;
    private int x_cord;
    private int y_cord;
    private int xCharacter;
    private int yCharacter;

    Random generator = new Random();
    private Image badacz;

    public Board(int size) {
        this.size = size;
        chambers = new Chamber[size][size];
        new Maze(size, chambers);
        setBackground(Color.GRAY);
        addKeyListener(Moving);
        try{
            badacz = ImageIO.read(new File("postac2.png"));
        }
        catch(IOException e) {
            e.printStackTrace();
        }
        yCharacter=1000/(size+2)*size;
        xCharacter=1000/(size+2)*size;

    }

    @Override
    public void paint(Graphics g) {
        int roomSize = getWidth()/(size+2);
        int x = x_cord= roomSize;
        int y = y_cord= roomSize;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size ; j++) {

                if ((chambers[i][j].N.DoesWallExist())) {
                    g.drawLine(x, y, x + roomSize, y);
                }

                if (chambers[i][j].W.DoesWallExist()) {
                    g.drawLine(x, y, x, y + roomSize);
                }
                if ((i == size - 1) && chambers[i][j].S.DoesWallExist()) {
                    g.drawLine(x, y + roomSize, x + roomSize,y + roomSize);
                }
                if ((j == size - 1) && chambers[i][j].E.DoesWallExist()) {
                    g.drawLine(x + roomSize, y, x + roomSize,y + roomSize);
                }
                x += roomSize;
            }

            x = x_cord;
            y += roomSize;
        }
        g.drawImage(badacz, xCharacter, yCharacter,roomSize, roomSize, window);
    }

    public KeyAdapter Moving= new KeyAdapter(){
        int roomSize = getWidth()/(size+2);

        @Override
        public void keyPressed (KeyEvent ev)
        {
            int x=(xCharacter-x_cord)/roomSize;
            int y=(yCharacter-y_cord)/roomSize;

            switch (ev.getKeyCode()){
                case KeyEvent.VK_UP:
                    if(chambers[x][y].N.DoesWallExist()&& !chambers[x][y].IsEndChamber()) xCharacter-=roomSize;
                    break;
                case KeyEvent.VK_DOWN:
                    if(chambers[x][y].S.DoesWallExist()&& !chambers[x][y].IsEndChamber()) xCharacter+=roomSize;
                    break;
                case KeyEvent.VK_RIGHT:
                    if(chambers[x][y].E.DoesWallExist()&& !chambers[x][y].IsEndChamber()) yCharacter+=roomSize;
                    break;
                case KeyEvent.VK_LEFT:
                    if(chambers[x][y].W.DoesWallExist()&& !chambers[x][y].IsEndChamber()) yCharacter-=roomSize;
                    break;
            }
            y=(xCharacter-x_cord)/roomSize;
            x=(yCharacter-y_cord)/roomSize;
            if (chambers[x][y].IsEndChamber()) {
                System.out.println("Brawo!");
            }
            repaint();
        }
    };

}
