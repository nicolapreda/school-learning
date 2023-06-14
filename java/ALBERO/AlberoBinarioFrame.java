import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;

import javax.swing.*;

public class AlberoBinarioFrame extends JFrame {

    private AlberoBinario albero;

    public AlberoBinarioFrame(AlberoBinario albero) {
        this.albero = albero;
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // imposta dimensioni finestra, imposta l'altezza in base alla profondità
        // dell'albero
        setSize(800, 800);

        setLocationRelativeTo(null);
        setTitle("Albero binario");
        setContentPane(new AlberoBinarioPanel(albero, this.getWidth(), this.getHeight()));

        JPanel panel = new JPanel();
        JButton button = new JButton("Conferma");

        JTextArea textArea = new JTextArea(2, 10);



        panel.add(button);
        panel.add(textArea);

        add(panel);
        setVisible(true);


        
        button.addActionListener(new ActionListener() { 
            public void actionPerformed(ActionEvent e) {
                String inputText = textArea.getText();
                LinkedList<Character> charList = new LinkedList<Character>(); //LinkedList per memorizzare i caratteri
                int[] charCounts = new int[256]; //array per tenere traccia del conteggio dei caratteri
                for (int i = 0; i < inputText.length(); i++) {
                   char currentChar = inputText.charAt(i);
                   charList.add(currentChar); //aggiungiamo il carattere alla LinkedList
                   charCounts[currentChar]++;
                }
                for (int i = 0; i < 256; i++) {
                   if (charCounts[i] > 0) {
                      System.out.println((char) i + ": " + charCounts[i] + "\n");
                   }
                }
    
                System.out.println("LinkedList: " + charList);
    
            }
        });

    }

}
