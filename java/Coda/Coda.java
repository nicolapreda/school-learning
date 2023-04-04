import java.util.LinkedList;

class Coda {
    //array coda
    LinkedList<Veicolo> coda;
  
    public Coda() {
      coda = new LinkedList<Veicolo>();
    }
  
    public void aggiungiVeicolo(Veicolo v) {
      if (coda.isEmpty()) {
        coda.add(v);
      } else {
        for (int i = 0; i < coda.size(); i++) {
          if (coda.get(i).priority > v.priority) {
            coda.add(i, v);
            break;
          }
        }
        if (!coda.contains(v)) {
          coda.addLast(v);
        }
      }
    }
  
    public void rimuoviVeicolo() {
      if (!coda.isEmpty()) {
        coda.removeFirst();
      } else {
        System.out.println("La coda è vuota");
      }
    }
  
    public void stampaCoda() {
      System.out.println("La coda dei veicoli è: ");
      for (Veicolo v : coda) {
        System.out.println(v.name + " (priorità " + v.priority + ")");
      }
    }
  }