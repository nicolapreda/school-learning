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
        

        
        numeratorField2=new JTextField();
        numeratorField2.setBounds(180,40,60,23); 
        JLabel LineaLabel=new JLabel("________");
        LineaLabel.setBounds(180,50,60,24);
        denominatorField2=new JTextField();
        denominatorField2.setBounds(180,75,60,23);
        
        add(numeratorField2);
        add(denominatorField2);
        add(LineaLabel);
        
        JButton simplifyButton = new JButton("=");
        simplifyButton.setBounds(260,40,60,60);
        simplifyButton.addActionListener(new ClickListener());
        add(simplifyButton);


        numeratorResult =new JTextField();
        numeratorResult.setBounds(340,40,60,23); 
        JLabel LIneaLabel=new JLabel("________");
        LIneaLabel.setBounds(340,50,60,24);
         denominatorResult=new JTextField();
        denominatorResult.setBounds(340,75,60,23);
        
        add(numeratorResult);
        add(denominatorResult);
        add(LIneaLabel);
        
        //aggiungi in basso alla finestra un bottone per calcolare l'approssimazione decimale, che verrà mostrata su una label sotto al bottone
        JButton decimalButton = new JButton("Decimal");
        decimalButton.setBounds(160,110,100,30);
        add(decimalButton);
        //add decimal label
        JLabel decimalLabel = new JLabel("");
        decimalLabel.setBounds(200, 140, 100, 30);
        
//aggiungi in basso a sinistra un tasto per resettare i campi
        JButton resetButton = new JButton("Reset");
       
        resetButton.setBounds(20,110,100,30);
        resetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                numeratorField1.setText("");
                denominatorField1.setText("");
                numeratorField2.setText("");
                denominatorField2.setText("");
                numeratorResult.setText("");
                denominatorResult.setText("");
                decimalLabel.setText("");
            }
        });
        add(resetButton);


        add(decimalLabel);
        setSize(430,200);
        setLayout(null);
        setVisible(true);


        decimalButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
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
                    switch (operationComboBox.getSelectedIndex()) {
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
                    //calcola l'approssimazione decimale
                    double decimal = (double) resultNumerator / resultDenominator;
                    //mostra l'approssimazione decimale in una label sotto al bottone
                    decimalLabel.setText(decimal + "");
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Valore non valido");
                }

            }
            
        });

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
