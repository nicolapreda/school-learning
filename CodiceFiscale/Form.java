import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


public class Form extends JFrame {

  // Campi per i dati necessari per il calcolo del codice fiscale
  private JTextField nomeField;
  private JTextField cognomeField;
  private JTextField dataField;
  private JTextField luogoField;
  private JRadioButton maschioButton;
  private JRadioButton femminaButton;

  public Form() {
    // Imposta il titolo della finestra
    super("Calcolo del codice fiscale");

    // Imposta il layout della finestra
    setLayout(new FlowLayout());

    // Aggiunge i campi per i dati necessari per il calcolo del codice fiscale
    add(new JLabel("Nome:"));
    nomeField = new JTextField(20);
    add(nomeField);

    add(new JLabel("Cognome:"));
    cognomeField = new JTextField(20);
    add(cognomeField);

    add(new JLabel("Data di nascita (gg/mm/aaaa):"));
    dataField = new JTextField(10);
    add(dataField);

    add(new JLabel("Luogo di nascita:"));
    luogoField = new JTextField(20);
    add(luogoField);

    add(new JLabel("Sesso:"));
    maschioButton = new JRadioButton("Maschio");
    femminaButton = new JRadioButton("Femmina");
    add(maschioButton);
    add(femminaButton);

    // Aggiunge il pulsante per il calcolo del codice fiscale
    JButton calcolaButton = new JButton("Calcola il codice fiscale");
    add(calcolaButton);
    calcolaButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        // Calcola il codice fiscale
        String cf = calcolaCodiceFiscale();

        // Visualizza il codice fiscale a schermo
        JOptionPane.showMessageDialog(Form.this, "Il tuo codice fiscale è: " + cf);
      }
    });

    // Imposta le dimensioni della finestra
    setSize(400, 200);

    // Imposta la finestra in modo che sia possibile chiuderla utilizzando la X
    // nell'angolo in alto a destra
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    // Imposta la posizione della finestra
    setLocationRelativeTo(null);

    // Visualizza la finestra
    setVisible(true);
  }

  // Metodo per il calcolo del codice fiscale
  private String calcolaCodiceFiscale() {
    // Recupera i dati inseriti dall'utente
    String nome = nomeField.getText().toUpperCase();
    String cognome = cognomeField.getText().toUpperCase();
    String data = dataField.getText();
    String luogo = luogoField.getText().toUpperCase();
    char sesso = maschioButton.isSelected() ? 'M' : 'F';

    // Codice fiscale parziale: primi 6 caratteri sono il cognome, poi il nome e poi
    // la data di nascita in formato aaaammgg
    String cfParziale = cognome + nome + data;

    // Carattere di controllo
    char ctrl = calcolaCarattereDiControllo(cfParziale);

    // Codice fiscale completo
    String cfCompleto = cfParziale + ctrl + luogo;

    return cfCompleto;
  }

  private char calcolaCarattereDiControllo(String cfParziale) {
    // Mappa che associa a ogni lettera del codice fiscale il suo valore di
    // controllo
    char[] map = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z' };

    // Somma dei valori di controllo
    int somma = 0;

    // Calcola il valore di controllo per ogni carattere del codice fiscale parziale
    for (int i = 0; i < cfParziale.length(); i++) {
      char c = cfParziale.charAt(i);
      int valore = 0;
      if (Character.isDigit(c)) {
        // Se il carattere è una cifra, il valore di controllo è uguale alla cifra
        // stessa
        valore = c - '0';
      } else {
        // Se il carattere è una lettera, il valore di controllo è dato dalla posizione
        // della lettera nella mappa
        valore = c - 'A';
      }
      // Aggiunge il valore di controllo alla somma
      somma += valore;
    }

    // Calcola il resto della divisione della somma per 26
    int resto = somma % 26;

    // Il carattere di controllo è la lettera corrispondente al resto della
    // divisione nella mappa
    return map[resto];
  }

  public static void main(String[] args) {
    Form form = new Form();
    String cf = form.calcolaCodiceFiscale();

  }
}
