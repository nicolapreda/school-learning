public class Televisore {
    int pollici;
    String schermo;
    String colore;
    int canale;
    int volume;
    int luminos;
    boolean acceso;
    
    public Televisore(int pollici, String schermo, String colore) {
        this.pollici = pollici;
        this.schermo = schermo;
        this.colore = colore;
        canale = 1;
        volume = 1;
        luminos = 1;
        acceso = false;
    }

    public void accendi() {
        acceso = true;
        System.out.println("Televisore acceso");
    }

    public void spegni() {
        acceso = false;
        System.out.println("Televisore spento");
    }
    public int getPollici() {
        return pollici;
    }
    public void setPollici(int pollici) {
        this.pollici = pollici;
    }
    public String getSchermo() {
        return schermo;
    }
    public void setSchermo(String schermo) {
        this.schermo = schermo;
    }
    public String getColore() {
        return colore;
    }
    public void setColore(String colore) {
        this.colore = colore;
    }
    public int getCanale() {
        return canale;
    }
    public void setCanale(int canale) {
        this.canale = canale;
    }
    public int aumentaCanale() {
        if (acceso) {
            canale++;
            if (canale > 999) {
                canale = 1;
            }
            System.out.println("Canale: " + canale);
        }
        return canale;
    }
    public int diminuisciCanale() {
        if (acceso) {
            canale--;
            if (canale < 1) {
                canale = 1;
            }
            System.out.println("Canale: " + canale);
        }
        return canale;
    }
    public int getVolume() {
        return volume;
    }

    public int aumentaVolume() {
        if (acceso) {
            volume++;
            if (volume > 10) {
                volume = 10;
            }
        }
        return volume;
    }
    public int diminuisciVolume() {
        if (acceso) {
            volume--;
            if (volume < 1) {
                volume = 1;
            }
        }
        return volume;
    }
    
    public int getLuminos() {
        return luminos;
    }
    
    public void aumentaLuminos(){
        if(acceso){
            luminos++;
            if(luminos>10){
                luminos=10;
            }
        }
    }

    public void diminuisciLuminos(){
        if(acceso){
            luminos--;
            if(luminos<1){
                luminos=1;
            }
        }
    }

public String toString(){
        String s="Telecomando: ";
        if(acceso){
            s+="Acceso";
        }
        else{
            s+="Spento";
        }
        s+=" Canale: "+canale+" Volume: "+volume+" Luminosità: "+luminos;
        return s;
    }

}
