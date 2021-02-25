import java.util.GregorianCalendar;

public class Calendar{
    private static Calendar INSTANCE;
    private GregorianCalendar properCalendar;

    private Calendar(){
        properCalendar = new GregorianCalendar();
    }


    public static Calendar getInstance(){
        if(INSTANCE == null){
            INSTANCE = new Calendar();
        }
        return INSTANCE;
    }

    public int getYear(){
        return properCalendar.get(GregorianCalendar.YEAR);
    }

    public int getMonth(){
        return properCalendar.get(GregorianCalendar.MONTH);
    }
}
