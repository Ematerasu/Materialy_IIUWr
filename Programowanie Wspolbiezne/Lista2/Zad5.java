import java.util.Arrays;

class PrefixSum implements Runnable{

    private int lo, hi;
    private int[] array;
    private int[] output;
    public PrefixSum(int[] array, int lo, int hi, int[] output)
    {
        this.array = array;
        this.lo = lo;
        this.hi = hi;
        this.output = output;
    }

    @Override
    public void run()
    {
        if(hi > lo){
            PrefixSum left = new PrefixSum(array, lo, (lo+hi)/2, output);
            PrefixSum right = new PrefixSum(array, (lo+hi)/2+1, hi, output);
            Thread l = new Thread(left);
            Thread r = new Thread(right);
            l.start();
            r.start();
            try {
                l.join();
                r.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
        else{
            output[lo] = array[lo];
        }
    }
}

public class Zad5{

    public static void main(String[] args) {

        int[] array = {1,4,3,67,32};
        int[] result = {0,0,0,0,0};
        PrefixSum prefixsum = new PrefixSum(array, 0, array.length, result);
        Thread thread = new Thread(prefixsum);
        thread.start();
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(Arrays.toString(result));
    }
}