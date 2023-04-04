public class Coda {
    private Veicolo codaVeicoli[];
    private int elementi; // numero degli elementi presenti nella coda
    private int head;
    private int tail;

    public Coda(int priority) {
        codaVeicoli = new Veicolo[priority];
        
    }


    public void enqueue(Veicolo veicolo) {
        int priority = veicolo.getPriority();
        
        if (elementi == codaVeicoli.length) {
            System.out.println("Coda piena");
        } else {
            codaVeicoli[tail] = veicolo;
            tail = (tail + 1) % codaVeicoli.length;
            elementi++;
        }
    }
}