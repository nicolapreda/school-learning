public class Lancio
{
    public static void main(String[] args){
        Televisore tv=new Televisore(27, "1920x1080", "nero");
        tv.accendi();
        tv.getPollici();
        tv.getSchermo();
        tv.getColore();
        tv.getCanale();
        tv.aumentaCanale();
        tv.diminuisciCanale();
        tv.getVolume();
        tv.aumentaVolume();
        tv.diminuisciVolume();
        tv.getLuminos();
        tv.aumentaLuminos();
        tv.diminuisciLuminos();
        tv.spegni();
        System.out.println(tv.toString());
        
    }
        
    
    
}
