import java.util.Date;

/**
 * Aggiungi qui una descrizione della classe Persona
 * 
 * @author (il tuo nome) 
 * @version (un numero di versione o una data)
 */
public class Persona
{
   private String nome;
   private String cognome;
   Date nascita;
   
   public Persona(String nome, String cognome, Date nascita){
        this.nome=nome;
        this.cognome=cognome;
        this.nascita=nascita;
   }
   
   public Persona(String nome, String cognome, int anno, int mese, int giorno){
        this.nome=nome;
        this.cognome=cognome;
        this.nascita=new Date(anno,mese,giorno);
   }

   public Persona(){

   }
   
   public String toString(){
        return ""; 
   }

   public int get_eta(){
       Date oggi=new Date();
       long eta_millisecondi=oggi.getTime()-nascita.getTime();
       long millisecondi_anno=1000L*60*60*24*365;
       return (int)(eta_millisecondi/millisecondi_anno); 
   }
   
   public int get_place(){
       return 0;
   }

    public String getNome() {
        return nome;
    }
    public String getCognome(){
        return cognome;
    }

}
