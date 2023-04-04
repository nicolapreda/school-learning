import javax.swing.*;
import java.awt.event.*;

public class Form extends JFrame {
    private JTextField numeratorField1;
    private JTextField denominatorField1;
    private JTextField numeratorField2;
    private JTextField denominatorField2;
    private JTextField numeratorResult;
    private JTextField denominatorResult;
    private JComboBox<String> operationComboBox;


    public Form() {
        setTitle("Frazione");         
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        
        numeratorField1=new JTextField();
        numeratorField1.setBounds(20,40,60,23); 
        JLabel lineaLabel=new JLabel("________");
        lineaLabel.setBounds(20,50,60,24);
        denominatorField1=new JTextField();
        denominatorField1.setBounds(20,75,60,23); 
        
        add(numeratorField1);
        add(denominatorField1);
        add(lineaLabel);

        // combobox
        operationComboBox = new JComboBox<String>();

        operationComboBox.addItem("+");
        operationComboBox.addItem("-");
        operationComboBox.addItem("*");
        operationComboBox.addItem("/");

        operationComboBox.setBounds(100, 45, 60, 50);
        add(operationComboBox);
        
        setSize(430,200);
        setLayout(null);
        setVisible(true);


        

    }
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    //create clicklistener class and pass an int argument
    private class ClickListener implements ActionListener {

        
        public void actionPerformed(ActionEvent e) {
            //prendi il risultato della combo box
            int operation = operationComboBox.getSelectedIndex();

            String firstFractionText = numeratorField1.getText() + "/" + denominatorField1.getText();
            String secondFractionText = numeratorField2.getText() + "/" + denominatorField2.getText();

            try {
                // parse numerator and denominator of first fraction
                int firstFractionNumerator = Integer.parseInt(firstFractionText.split("/")[0]);
                int firstFractionDenominator = Integer.parseInt(firstFractionText.split("/")[1]);
    
                // parse numerator and denominator of second fraction
                int secondFractionNumerator = Integer.parseInt(secondFractionText.split("/")[0]);
                int secondFractionDenominator = Integer.parseInt(secondFractionText.split("/")[1]);
                //in base al numero passato fai addizione, sottrazione, moltiplicazione o divisione
                int resultNumerator = 0;
                int resultDenominator = 0;
                switch (operation) {
                    case 00:
                        resultNumerator = (firstFractionNumerator * secondFractionDenominator) + (secondFractionNumerator * firstFractionDenominator);
                        resultDenominator = firstFractionDenominator * secondFractionDenominator;
                        break;
                    case 1:
                        resultNumerator = (firstFractionNumerator * secondFractionDenominator) - (secondFractionNumerator * firstFractionDenominator);
                        resultDenominator = firstFractionDenominator * secondFractionDenominator;
                        break;
                    case 2:
                        resultNumerator = firstFractionNumerator * secondFractionNumerator;
                        resultDenominator = firstFractionDenominator * secondFractionDenominator;
                        break;
                    case 3:
                        resultNumerator = firstFractionNumerator * secondFractionDenominator;
                        resultDenominator = firstFractionDenominator * secondFractionNumerator;
                        break;
                }
    
                // simplify the result
                int gcd = gcd(resultNumerator, resultDenominator);
                resultNumerator = resultNumerator / gcd;
                resultDenominator = resultDenominator / gcd;
    
                // display the result
                numeratorResult.setText(resultNumerator + "");
                denominatorResult.setText(resultDenominator + "");
            } catch (NumberFormatException exception) {
                JOptionPane.showMessageDialog(Form.this, "Valore inserito non valido. Inserisci una frazione negli spazi appositi 'a/b'.");
            }
        }
    }

    
    
    public static void main(String[] args) {
        Form calculator = new Form();
        calculator.setVisible(true);
    }
}
