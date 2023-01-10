public class Main {
  public static void main(String[] args) throws InterruptedException {
    Campana DIN = new Campana("DIN");
    Campana DON = new Campana("DON");
    Campana DAN = new Campana("DAN");

    DIN.suonaInThread();
    DIN.aspetta();
    
    DON.suonaInThread();
    DON.aspetta();
    
    DAN.suonaInThread();
    DAN.aspetta();
  }
}
