public class Frazione {
  private int num;
  private int den;

  // costruttore senza parametri, inizializza a 0 il numeratore e a 1 il
  // denominatore
  public Frazione() {
    this.num = 0;
    this.den = 1;
  }

  // costruttore che riceve come solo parametro il numeratore
  public Frazione(int num) {
    this.num = num;
    this.den = 1;
  }

  // costruttore che riceve come parametri il numeratore e il denominatore
  public Frazione(int num, int den) {
    this.num = num;
    this.den = den;
  }

  // metodo per ottenere il numeratore della frazione
  public int getNum() {
    return this.num;
  }

  // metodo per ottenere il denominatore della frazione
  public int getDen() {
    return this.den;
  }

  // metodo per impostare il numeratore della frazione
  public void setNum(int num) {
    this.num = num;
  }

  // metodo per impostare il denominatore della frazione
  public void setDen(int den) {
    this.den = den;
  }

  // metodo per calcolare la somma di due frazioni
  public Frazione somma(Frazione f) {
    int num = this.num * f.getDen() + this.den * f.getNum();
    int den = this.den * f.getDen();
    Frazione somma = new Frazione(num, den);
    somma.riduci();
    return somma;
  }

  // metodo per calcolare la differenza tra due frazioni
  public Frazione sottrai(Frazione f) {
    int num = this.num * f.getDen() - this.den * f.getNum();
    int den = this.den * f.getDen();
    Frazione differenza = new Frazione(num, den);
    differenza.riduci();
    return differenza;
  }

  // metodo per calcolare il prodotto di due frazioni
  public Frazione per(Frazione f) {
    int num = this.num * f.getNum();
    int den = this.den * f.getDen();
    Frazione prodotto = new Frazione(num, den);
    prodotto.riduci();
    return prodotto;
  }

  // metodo per calcolare la divisione di due frazioni
  public Frazione diviso(Frazione f) {
    int num = this.num * f.getDen();
    int den = this.den * f.getNum();
    Frazione divisione = new Frazione(num, den);
    divisione.riduci();
    return divisione;
  }

  // metodo per semplificare una frazione tramite l'algoritmo di Euclide (usando
  // la ricorsione)
  public void riduci() {
    int mcd = calcolaMCD(this.num, this.den);
    this.num /= mcd;
    this.den /= mcd;
  }

  // metodo per calcolare il massimo comun divisore di due numeri interi
  private int calcolaMCD(int a, int b) {
    if (b == 0) {
      return a;
    }
    return calcolaMCD(b, a % b);
  }

  // metodo per ottenere il numero con la virgola relativo alla frazione
  public double valore() {
    return (double) this.num / this.den;
  }

  // metodo per ottenere una stringa che rappresenta la frazione
  public String toString() {
    return this.num + "/" + this.den;
  }

  // metodo per verificare se una frazione è maggiore di un'altra
  public boolean maggiore(Frazione f) {
    return this.valore() > f.valore();
  }

  // metodo per verificare se una frazione è minore di un'altra
  public boolean minore(Frazione f) {
    return this.valore() < f.valore();
  }

  // metodo per verificare se due frazioni sono uguali
  public boolean equals(Frazione f) {
    return this.num == f.getNum() && this.den == f.getDen();
  }

}
