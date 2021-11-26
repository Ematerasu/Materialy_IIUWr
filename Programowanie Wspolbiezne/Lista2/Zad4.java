class LongestRepeatingSequence implements Runnable{
    public int arr[];
    public int res[];

    LongestRepeatingSequence(int arr[], int res[]){
        this.arr = arr;
        this.res = res;
    }
    @Override
    public void run(){
        if(arr.length > 1){
        }
    }
}

public class Zad4{
    public static void main(String[] args) {  
        int arr[] = {1,2,1,2,1,2,1,2,3,3,3};
        int res[] = {};
        LongestRepeatingSequence w = new LongestRepeatingSequence(arr, res);

        Thread t = new Thread(w);

        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < 4; i++)
            System.out.printf("%d ", arr[i]);
    }
}