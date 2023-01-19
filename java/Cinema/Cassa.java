import java.util.Scanner;

public class Cassa {
    //crea classe di avvio
    public static void main(String[] args) {
        //crea una coda di persone con un numero casuale
        Coda coda = new Coda();
        //crea oggetto persona
        Persona persona = new Persona("Giorgio", "Vanni", 1970, 7, 9);
        Persona persona1 = new Persona("Giacomo", "Poretti", 1964, 7, 9);

        //crea oggetto sala
        SalaCinematografica sala = new SalaCinematografica("Il Signore degli Anelli", 100);
        
        System.out.println("Premi 1 per metterti in coda alla cassa");
        //prendi in input un numero
        Scanner sc=new Scanner(System.in);

        int comando=sc.nextInt();
        if(comando == 1){
            System.out.println("Ci sono " + Coda.getPersoneInCoda() + " persone in coda.");

            Coda.aggiungiInCoda(persona);
            System.out.println("Ci sono " + Coda.getPersoneInCoda() + " persone in coda.");

            Coda.aggiungiInCoda(persona1);
            //stampa i nomi delle persone in coda
            System.out.println("I nomi delle persone in coda sono:" + Coda.getNomiPersoneInCoda());
            System.out.println("Ci sono " + Coda.getPersoneInCoda() + " persone in coda.");
            Coda.estraiDallaCoda();
            System.out.println("Ci sono " + Coda.getPersoneInCoda() + " persone in coda.");
            Coda.estraiDallaCoda();

            if(Coda.getPersoneInCoda() == "0"){
                vendiBiglietto(persona, sala);
            }

        }
    }
    

    public static void vendiBiglietto(Persona persona, SalaCinematografica sala) {
        if (sala.postiDisponibili > 0) {
            sala.postiDisponibili--;
            System.out.println("Biglietto venduto a " + persona.getNome() + " per la proiezione " + sala.getProiezione());
        } else {
            System.out.println("Spiacenti, tutti i posti sono occupati.");
        }
    }
}
