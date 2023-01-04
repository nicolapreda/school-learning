
/**
 * Aggiungi qui una descrizione della classe Telecomando
 * 
 * @author (il tuo nome) 
 * @version (un numero di versione o una data)
 */
public class Telecomando
{
    private int canale;
    private int volume;
    private int luminosita;
    private boolean acceso;


    /**
     * Costruttore degli oggetti di classe  Telecomando
     */
    public Telecomando()
    {
        canale=1;
        volume=1;
        luminosita=1;
        acceso=false;

    }

    
    public void accendi(){
        acceso=true;
        System.out.println("Televisore acceso");
    }

    public void spegni(){
        acceso=false;
        System.out.println("Televisore spento");

    }

    public void cambiaCanale(){
        if(acceso){
            canale++;
            if(canale>999){
                canale=1;
            }
            System.out.println("Canale: "+canale);
        }

    }

    public void aumentaVolume(){
        if(acceso){
            volume++;
            if(volume>10){
                volume=10;
            }
        }
    }

    public void diminuisciVolume(){
        if(acceso){
            volume--;   
            if(volume<1){
                volume=1;
            }
        }
    }   

    public void aumentaLuminosita(){
        if(acceso){
            luminosita++;
            if(luminosita>10){
                luminosita=10;
            }
        }
    }

    public void diminuisciLuminosita(){
        if(acceso){
            luminosita--;
            if(luminosita<1){
                luminosita=1;
            }
        }
    }

    



}
