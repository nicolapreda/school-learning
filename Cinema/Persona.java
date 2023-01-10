import java.util.Date;

public class Persona 
{
    private String surname;
    private String name;
    Date nascita;

    public Persona(String surname, String name, Date nascita) 
    {
        this.surname = surname;
        this.name = name;
        this.nascita = nascita;
    }

    public Persona(String surname, String name, Date nascita, int anno, int mese, int giorno) 
    {
        this.surname = surname;
        this.name = name;
        this.nascita = new Date(giorno, mese, anno);
    }

    public long eta() 
    {
        Date oggi = new Date();
        long eta = oggi.getTime() - nascita.getTime();
        return eta= 1900 + (eta / 1000 / 60 / 60 / 24 / 365);
        
    }
    
}
