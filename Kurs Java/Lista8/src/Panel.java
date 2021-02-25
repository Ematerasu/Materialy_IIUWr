import javax.swing.*;
import java.awt.*;

public class Panel extends JTabbedPane {
    private Calendar instanceOfCalendar;
    private JPanel tabYear, tabMonth;
    private JPanel[] miesiace;

    public Panel(){
        super(JTabbedPane.TOP);
        instanceOfCalendar = Calendar.getInstance();

        tabYear = new JPanel();
        tabYear.add(new JLabel("asf"));
        //miesiace = new JPanel[12];
        String year = "Rok" + instanceOfCalendar.getYear();
        //String month = "" + instanceOfCalendar.getMonth();
        tabYear.setLayout(new GridLayout(4, 3));


        addTab(year, tabYear);
        //addTab(month, tabMonth);

    }
    
}
