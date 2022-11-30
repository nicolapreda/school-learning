
/**
 * Aggiungi qui una descrizione della classe Automobile
 * 
 * @author (il tuo nome)
 * @version (un numero di versione o una data)
 */
public class Automobile {
    // variabili d'istanza - sostituisci l'esempio che segue con il tuo
    private String marca;
    private String modello;
    private boolean accesa;
    private int cilindrata;
    private int serbatoio;
    private int velocita;
    private int marcia;

    /**
     * Costruttore degli oggetti di classe Automobile
     */
    public Automobile() {
        marca = "Fiat";
        modello = "Grande Punto";
        accesa = false;
        cilindrata = 1200;
        serbatoio = 50;
        velocita = 0;
        marcia = 0;
    }

    /**
     * Un esempio di metodo - aggiungi i tuoi commenti
     * 
     * @param y un parametro d'esempio per un metodo
     * @return la somma di x e y
     */
    public void avviaMotore() {
        if (accesa == false) {
            accesa = true;
            System.out.println("Motore avviato");

        } else {
            System.out.println("Motore già avviato!");
        }
    }

    public void saliMarcia() {
        if (marcia < 5) {
            marcia++;
            System.out.println("Marcia aumentata di uno!");
        }

        else
            System.out.println("Massima marcia raggiunta!");
    }

    public void scendiMarcia() {
        if (marcia > 1) {
            marcia--;
            System.out.println("Marcia scesa di uno!");
        }

        else
            System.out.println("Massima marcia raggiunta!");
    }

    public void accelera() {
        if (velocita < 200) {
            velocita += 10;
            System.out.println("Velocità aumentata di 10!");
        } else
            System.out.println("Velocità massima raggiunta!");
    }

    public void frena() {
        if (velocita > 0) {
            velocita -= 10;
            System.out.println("Velocità diminuita di 10!");
        } else
            System.out.println("Impossibile frenare maggiormente!");
    }

    public void ferma() {
        if (accesa == true) {
            accesa = false;
            System.out.println("Motore spento!");
        } else
            System.out.println("Motore già spento!");
    }

    public void riempi(int k) {
        if (k > 0) {
            serbatoio += k;
            System.out.println("Serbatoio riempito di " + k + " litri!");
        } else
            System.out.println("Impossibile riempire il serbatoio!");
    }

    public void mostraStato() {
        System.out.println("Marca: " + marca);
        System.out.println("Modello: " + modello);
        System.out.println("Cilindrata: " + cilindrata);
        System.out.println("Serbatoio: " + serbatoio);
        System.out.println();
        System.out.println();
        if (accesa == true) {
            System.out.println("Motore: Acceso");
            System.out.println("Velocità: " + velocita);
            System.out.println("Marcia: " + marcia);

        } else {
            System.out.println("Motore: Spento");

        }

    }

    public int getSerbatoio() {
        return serbatoio;
    }

    public int getVelocita() {
        return velocita;
    }

}
