import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Form extends JFrame {
  // Campi di testo per richiedere il nome, il cognome, la data di nascita, il comune di nascita e il sesso
  private JTextField nameField, surnameField, birthDateField, birthPlaceField, sexField;
  
  // Pulsante per il calcolo del codice fiscale
  private JButton calculateButton;
  
  // Etichetta per visualizzare il codice fiscale calcolato
  private JLabel cfLabel;
  
  public Form() {
        // Imposta il titolo della finestra
        super("Calcolatore di Codice Fiscale");
    
        // Imposta il layout della finestra
        setLayout(new BorderLayout());
        
        
        // Crea un pannello per i campi di testo
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(5, 2));
        inputPanel.setOpaque(false);
        
        // Aggiunge i campi di testo al pannello
        nameField = new JTextField(20);
        surnameField = new JTextField(20);
        birthDateField = new JTextField(20);
        birthPlaceField = new JTextField(20);
        sexField = new JTextField(20);
        inputPanel.add(new JLabel("Nome:"));
        inputPanel.add(nameField);
        inputPanel.add(new JLabel("Cognome:"));
        inputPanel.add(surnameField);
        inputPanel.add(new JLabel("Data di nascita (gg/mm/aaaa):"));
        inputPanel.add(birthDateField);
        inputPanel.add(new JLabel("Comune di nascita:"));
        inputPanel.add(birthPlaceField);
        inputPanel.add(new JLabel("Sesso (M o F):"));
        inputPanel.add(sexField);
        
        // Aggiunge il pannello con i campi di testo alla finestra
        add(inputPanel, BorderLayout.NORTH);
        
        // Aggiunge il pulsante di calcolo
        calculateButton = new JButton("Calcola Codice Fiscale");
        add(calculateButton, BorderLayout.CENTER);
        
        // Aggiunge l'etichetta per il codice fiscale calcolato
        cfLabel = new JLabel("Codice Fiscale: ");
        cfLabel.setFont(new Font("Serif", Font.PLAIN, 18));
        cfLabel.setForeground(Color.BLUE);
        add(cfLabel, BorderLayout.SOUTH);
    
    
    // Crea un listener per il pulsante di calcolo
    calculateButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        // Recupera i dati inseriti dall'utente
        String name = nameField.getText();
        String surname = surnameField.getText();
        String birthDate = birthDateField.getText();
        String birthPlace = birthPlaceField.getText();
        String sex = sexField.getText();
        
        // Calcola il codice fiscale
        String cf = calculateCF(name, surname, birthDate, birthPlace, sex);
        
        // Aggiorna l'etichetta per visualizzare il codice fiscale calcolato
        cfLabel.setText("Codice Fiscale: " + cf);
      }
    });}

  
  // Metodo per calcolare il codice fiscale
    // Metodo per calcolare il codice fiscale
    private String calculateCF(String name, String surname, String birthDate, String birthPlace, String sex) {
      // Pulisce i dati inseriti dall'utente, eliminando gli spazi iniziali e finali
      name = name.trim();
      surname = surname.trim();
      birthDate = birthDate.trim();
      birthPlace = birthPlace.trim();
      sex = sex.trim();
      

      // Verifica che tutti i dati siano stati inseriti
      if (name.isEmpty() || surname.isEmpty() || birthDate.isEmpty() || birthPlace.isEmpty() || sex.isEmpty()) {
        return "Errore: tutti i dati sono obbligatori!";
      }
      
      // Verifica che la data di nascita sia nel formato gg/mm/aaaa
      if (!birthDate.matches("\\d{2}/\\d{2}/\\d{4}")) {
        return "Errore: la data di nascita non è nel formato gg/mm/aaaa!";
      }
      
      // Verifica che il sesso sia M o F
      if (!sex.equalsIgnoreCase("M") && !sex.equalsIgnoreCase("F")) {
        return "Errore: il sesso deve essere M o F!";
      }
      
      // Recupera i singoli elementi della data di nascita (giorno, mese e anno)
      String[] elements = birthDate.split("/");
      int day = Integer.parseInt(elements[0]);
      int month = Integer.parseInt(elements[1]);
      int year = Integer.parseInt(elements[2]);
      
      // Calcola il codice fiscale
      String cf = surname.toUpperCase();
      /*Dobbiamo ricavare 3 lettere per il cognome e tre lettere per il nome in uppercase da aggiungere. 
      Bisogna prendere la prima, la seconda e la terza consonante. 
      Però potrebbe anche succedere che ci siano solo due consonanti oppure una sola; in tal caso dopo aver preso 
      le consonanti si inizia a prendere anche le vocali. 
      Se ancora mancano altre lettere per completare la nostra stringa di tre caratteri si aggiunge la lettera X.
      I cognomi composti da più parole vanno considerati come se fossero una sola parola.*/
      cf = cf.replaceAll("[AEIOU]", "");
      cf = cf.replaceAll("[' ']", "");
      if (cf.length() < 3) {
        cf += surname.toUpperCase().replaceAll("[^AEIOU]", "");
      }
      if (cf.length() < 3) {
        cf += surname.toUpperCase().replaceAll("[AEIOU]", "");
      }
      if (cf.length() < 3) {
        cf += "XXX";
      }
      cf = cf.substring(0, 3);
      cf += name.toUpperCase();
      cf = cf.replaceAll("[AEIOU]", "");
      cf = cf.replaceAll("[' ']", "");
      if (cf.length() < 6) {
        cf += name.toUpperCase().replaceAll("[^AEIOU]", "");
      }
      if (cf.length() < 6) {
        cf += name.toUpperCase().replaceAll("[AEIOU]", "");
      }
      if (cf.length() < 6) {
        cf += "XXX";
      }
      cf = cf.substring(0, 6);

      cf += birthYear(year);
      cf += birthMonth(month);
      cf += birthDay(day, sex, year, month);
      /*verifica se birthPlaceField è presente all'interno del file comuni.txt nella prima colonna.
      In caso affermativo, aggiungi a cf la seconda colonna del file.
      Se non viene trovato nel file ritorna errore */
      try {
        BufferedReader br = new BufferedReader(new FileReader("comuni.txt"));
        String line = br.readLine();
        while (line != null) {
          String[] comune = line.split("\t");
          if (comune[0].equalsIgnoreCase(birthPlace)) {
            cf += comune[1];
            break;
          }
          line = br.readLine();
        }
        br.close();
      } catch (IOException e) {
        return "Errore: il file comuni.txt non è stato trovato!";
      }
      

      cf += controlCode(cf);
      
      return cf;
    }
    
      // Restituisce la parte corrispondente all'anno di nascita del codice fiscale
  private String birthYear(int year) {
    return String.format("%02d", year % 100);
  }
  
  // Restituisce la parte corrispondente al mese di nascita del codice fiscale
  private String birthMonth(int month) {
    char[] months = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'};
    return String.valueOf(months[month - 1]);
  }
  
  // Restituisce la parte corrispondente al giorno e al sesso di nascita del codice fiscale
  private String birthDay(int day, String sex, int year, int month) {
    if (sex.equalsIgnoreCase("M")) {
      return String.format("%02d", day);
    } else {
      return String.format("%02d", day + 40);
    }
  }
  
    // Restituisce il carattere di controllo del codice fiscale
    private String controlCode(String cf) {
      String check = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      int sum = 0;
      for (int i = 1; i <= 15; i++) {
        char c = cf.charAt(i - 1);
        if (Character.isLetter(c)) {
          sum += (int)c;
        } else {
          sum += Character.getNumericValue(c);
        }
      }
      return String.valueOf(check.charAt(sum % 26));
    
  
  
 
}
public static void main(String[] args) {
  Form form = new Form();
  //imposta la finestra come non ridimensionabile
  
  // Imposta le dimensioni della finestra
  form.setSize(600, 400);
  
  // Imposta la finestra come non ridimensionabile
  form.setResizable(false);
  
  // Imposta la finestra come visibile
  form.setVisible(true);

}
}
