public class Avvio{
    public static void main(String[] args) {
        Frazione f1 = new Frazione(3, 4);
        Frazione f2 = new Frazione(5, 8);
        Frazione f3 = new Frazione(1, 2);
        // calcolo della somma di due frazioni
        Frazione somma = f1.somma(f2);
        System.out.println("La somma di " + f1 + " e " + f2 + " è " + somma);
        
        // calcolo della differenza tra due frazioni
        Frazione differenza = f1.sottrai(f2);
        System.out.println("La differenza tra " + f1 + " e " + f2 + " è " + differenza);
        
        // calcolo del prodotto di due frazion
        Frazione prodotto = f1.per(f2);
        System.out.println("Il prodotto di " + f1 + " e " + f2 + " è " + prodotto);
        
        // calcolo della divisione di due frazioni
        Frazione divisione = f1.diviso(f2);
        System.out.println("La divisione di " + f1 + " e " + f2 + " è " + divisione);
        
        // verifica se una frazione è maggiore di un'altra
        boolean maggiore = f1.maggiore(f3);
        System.out.println(f1 + " è maggiore di " + f3 + ": " + maggiore);
        
        // verifica se una frazione è minore di un'altra
        boolean minore = f1.minore(f3);
        System.out.println(f1 + " è minore di " + f3 + ": " + minore);
        
        // verifica se due frazioni sono uguali
        boolean uguali = f1.equals(f3);
        System.out.println(f1 + " è uguale a " + f3 + ": " + uguali);
    }
}


