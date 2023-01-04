public class dindondan {
    public static void main(String args[]) {
        // prima modalità di definizione
        Runnable cam1 = new Campana("din", 5);
        Thread thr1 = new Thread(cam1);
        thr1.start();
        // seconda modalità di definizione
        Thread thr2 = new Thread(new Campana("don", 5));
        thr2.start();
        // terza modalità di definizione
        new Thread(new Campana("dan", 5)).start();
    }
}