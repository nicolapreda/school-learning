import java.util.concurrent.CountDownLatch;

class Campana implements Runnable {
    private String nome;
    private Thread thread;
  
    public Campana(String nome) {
      this.nome = nome;
    }
  
    public void run() {
      System.out.println(nome);
    }
  
    public void suonaInThread() {
      thread = new Thread(this);
      thread.start();
    }
  
    public void aspetta() throws InterruptedException {
      thread.join();
    }
  }
  
