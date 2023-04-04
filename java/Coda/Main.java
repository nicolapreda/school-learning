

public class Main {
    public static void main(String[] args) {
      Coda coda = new Coda();
  
      Veicolo v1 = new Veicolo(1, "Veicolo 1");
      Veicolo v2 = new Veicolo(2, "Veicolo 2");
      Veicolo v3 = new Veicolo(1, "Veicolo 3");
      Veicolo v4 = new Veicolo(2, "Veicolo 4");
  
      coda.aggiungiVeicolo(v1);
      coda.aggiungiVeicolo(v2);
      coda.aggiungiVeicolo(v3);
      coda.aggiungiVeicolo(v4);
  
      coda.stampaCoda();
    }
  }