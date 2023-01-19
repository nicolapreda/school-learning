import java.util.LinkedList;
import java.util.Queue;

class Coda {
    private static Queue<Persona> personeInCoda;

    public Coda() {
        personeInCoda = new LinkedList<>();
    }

    public static void aggiungiInCoda(Persona persona) {
        personeInCoda.add(persona);
        System.out.println(persona.getNome() + " è stato aggiunto alla coda.");
    }

    public static Persona estraiDallaCoda() {
        Persona persona = personeInCoda.poll();
        if (persona != null) {
            System.out.println(persona.getNome() + " è stato estratto dalla coda.");
        }
        return persona;
    }
    public static String getPersoneInCoda(){
        int personeInCodaInt = personeInCoda.size();
        String personeInCodaString = Integer.toString(personeInCodaInt);
        return personeInCodaString;
    }

    //ritorna i nomi di tutte le persone in coda utilizzando un for each
    public static String getNomiPersoneInCoda() {
        String nomiPersoneInCoda = "";
        for (Persona persona : personeInCoda) {
            nomiPersoneInCoda += persona.getNome() + " ";
        }
        return nomiPersoneInCoda;
    }   

    

}   
