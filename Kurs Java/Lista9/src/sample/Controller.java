package sample;

import javafx.fxml.FXML;

import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

import java.math.BigInteger;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.concurrent.ExecutorService;

public class Controller implements Initializable {

    private enum Turn{
        NUMBER, OPERATOR
    }

    private enum NumberSystem{
        BINARY, DECIMAL, HEX
    }

    int pomLength;

    private Turn turn;
    private NumberSystem system;

    @FXML
    private TextField textField;

    @FXML
    private Button number2, number3, number4, number5, number6, number7, number8, number9, numberA, numberB, numberC, numberD, numberE, numberF;

    @FXML
    public void initialize(URL url, ResourceBundle rb){
        turn = Turn.NUMBER;
        system = NumberSystem.DECIMAL;
        numberA.setOpacity(0.5);
        numberB.setOpacity(0.5);
        numberC.setOpacity(0.5);
        numberD.setOpacity(0.5);
        numberE.setOpacity(0.5);
        numberF.setOpacity(0.5);
        pomLength = 0;
    }

    @FXML
    private void getChar(MouseEvent e) {
        Button button = (Button) e.getSource();
        String text = button.getText();
        if("01()".contains(text) && system == NumberSystem.BINARY) {
            textField.setText(textField.getText() + text);
            pomLength++;
            turn = Turn.OPERATOR;
        }
        else if("0123456789()".contains(text) && system == NumberSystem.DECIMAL) {
            textField.setText(textField.getText() + text);
            pomLength++;
            turn = Turn.OPERATOR;
        }
        else if("0123456789ABCDEF()".contains(text) && system == NumberSystem.HEX) {

            textField.setText(textField.getText() + text);
            pomLength++;
            turn = Turn.OPERATOR;
        }
        else if(text.contains("+/-"))
        {
            if(textField.getText().charAt(0) == '-') {
                textField.setText(textField.getText().substring(1));
            }
            else {
                text = "-";
                textField.setText(text + textField.getText());
            }

            turn = Turn.OPERATOR;
        }
        else if("+-*/^%n!".contains(text) && turn == Turn.OPERATOR) {
            if(text.contains("!")) {
                textField.setText(textField.getText().substring(0, textField.getText().length()-pomLength) + "fact(" + textField.getText().substring(textField.getText().length()-pomLength) + ")");
            }
            else {
                textField.setText(textField.getText() + text);
                pomLength=0;
                turn = Turn.NUMBER;
            }
        }
        else if(text.contains("(n)") && turn == Turn.OPERATOR) {
            textField.setText(textField.getText().substring(0, textField.getText().length()-pomLength) + "newton(" + textField.getText().substring(textField.getText().length()-pomLength) + ",");

        }

    }

    @FXML
    private void clear(MouseEvent e) {
        textField.setText("");
        turn = Turn.NUMBER;
        pomLength=0;
    }

    @FXML
    private void backspace(MouseEvent e) {
        textField.setText(textField.getText(0, textField.getText().length()-1));
        pomLength-=1;
    }

    @FXML
    private void setSystem(MouseEvent e){
        Button button = (Button) e.getSource();
        String text = button.getText();

        switch(text){
            case "(2)":
                system = NumberSystem.BINARY;
                number2.setOpacity(0.5);
                number3.setOpacity(0.5);
                number4.setOpacity(0.5);
                number5.setOpacity(0.5);
                number6.setOpacity(0.5);
                number7.setOpacity(0.5);
                number8.setOpacity(0.5);
                number9.setOpacity(0.5);
                numberA.setOpacity(0.5);
                numberB.setOpacity(0.5);
                numberC.setOpacity(0.5);
                numberD.setOpacity(0.5);
                numberE.setOpacity(0.5);
                numberF.setOpacity(0.5);
                break;
            case "(10)":
                system = NumberSystem.DECIMAL;
                number2.setOpacity(1.0);
                number3.setOpacity(1.0);
                number4.setOpacity(1.0);
                number5.setOpacity(1.0);
                number6.setOpacity(1.0);
                number7.setOpacity(1.0);
                number8.setOpacity(1.0);
                number9.setOpacity(1.0);
                numberA.setOpacity(0.5);
                numberB.setOpacity(0.5);
                numberC.setOpacity(0.5);
                numberD.setOpacity(0.5);
                numberE.setOpacity(0.5);
                numberF.setOpacity(0.5);
                break;
            case "(16)":
                system = NumberSystem.HEX;
                number2.setOpacity(1.0);
                number3.setOpacity(1.0);
                number4.setOpacity(1.0);
                number5.setOpacity(1.0);
                number6.setOpacity(1.0);
                number7.setOpacity(1.0);
                number8.setOpacity(1.0);
                number9.setOpacity(1.0);
                numberA.setOpacity(1.0);
                numberB.setOpacity(1.0);
                numberC.setOpacity(1.0);
                numberD.setOpacity(1.0);
                numberE.setOpacity(1.0);
                numberF.setOpacity(1.0);
                break;
        }

    }

    @FXML
    private void parse(MouseEvent e){
        String expression = textField.getText();

        try{
            if(system == NumberSystem.DECIMAL) {
                Expression eq = new Expression(expression, 10);
                textField.setText(eq.eval().toString());
            }
            else if(system == NumberSystem.BINARY){
                Expression eq = new Expression(expression, 2);
                textField.setText(eq.eval().toString(2));
            }
            else if(system == NumberSystem.HEX){
                Expression eq = new Expression(expression, 16);
                textField.setText(eq.eval().toString(16));
            }

        }
        catch(Exception ex){
            //ex.printStackTrace();
            textField.setText("error");
        }

    }

}
