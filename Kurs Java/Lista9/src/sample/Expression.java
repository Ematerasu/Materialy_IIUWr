package sample;


import java.math.BigInteger;

public class Expression {

    private String str;
    private int radix;

    public Expression(String eq, int rad){
        this.str = eq;
        this.radix = rad;
    }

    private int fact(int x){
        if(x == 1) return x;

        return x*fact(x-1);
    }

    int pos = -1;
    int ch;

    void nextChar() {
        pos++;
        if(pos < str.length()){
            ch = str.charAt(pos);
        }
        else ch = -1;
    }

    boolean eat(int charToEat) {
        if (ch == charToEat) {
            nextChar();
            return true;
        }
        return false;
    }


    /*
        Kolejnosc wykonywania dzialan: eval3(dodawanie, odejmowanie)
                                       eval2(mnozenie, dzielenie, modulo)
                                       eval1(potegowanie, silnia)
     */


    BigInteger eval3() {
        BigInteger x = eval2();
        while(true) {
            if      (eat('+')) x = x.add(eval2());
            else if (eat('-')) x = x.subtract(eval2());
            else return x;
        }
    }

    BigInteger eval2() {
        BigInteger x = eval1();
        while(true) {
            if      (eat('*')) x = x.multiply(eval1());
            else if (eat('/')) x = x.divide(eval1());
            else if (eat('%')) x = x.mod(eval1());
            else return x;
        }
    }

    BigInteger eval1() {
        if (eat('-')) return eval1().multiply(BigInteger.valueOf(-1));

        BigInteger x = new BigInteger("1");
        int startPos = this.pos;

        if (eat('(')) {
            x = eval3();
            eat(')');
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')) {
            while ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')) nextChar();
            x = new BigInteger((str.substring(startPos, this.pos)), radix);
        }
        else if (ch >= 'a' && ch <= 'z') {
            while (ch >= 'a' && ch <= 'z') nextChar();
            String func = str.substring(startPos, this.pos);
            if (func.equals("fact")) {
                x = eval1();
                x = BigInteger.valueOf(fact(x.intValue()));
            }
            //TODO newton
        }

        if(eat('^')) x = x.pow(eval1().intValue());


        return x;
    }

    public BigInteger eval(){
        nextChar();
        BigInteger x = eval3();
        return x;
    }
}
