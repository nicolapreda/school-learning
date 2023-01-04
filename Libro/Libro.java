public class Libro {

    private String autore;
    private String titolo;
    private int numeroPagine;
    private String codiceISBN;

    public Libro(String autore, String titolo, int numeroPagine, String codiceISBN) {
        this.autore = autore;
        this.titolo = titolo;
        this.numeroPagine = numeroPagine;
        this.codiceISBN = codiceISBN;
    }

    public void setautore(String autore) {
        this.autore = autore;
    }

    public String getautore() {
        return autore;
    }

    public void settitolo(String titolo) {
        this.titolo = titolo;
    }

    public String gettitolo() {
        return titolo;
    }

    public void setnumeroPagine(int np) {
        this.numeroPagine = np;
    }

    public int getnumeroPagine() {
        return numeroPagine;
    }

    public void setcodiceISBN(String codiceISBN) {
        this.codiceISBN = codiceISBN;
    }

    public String getcodiceISBN() {
        return codiceISBN;
    }

    public void visualizza() {
        System.out.println("Autore: " + autore);
        System.out.println("Titolo: " + titolo);
        System.out.println("Numero Pagine: " + numeroPagine);
        System.out.println("Codice ISBN: " + codiceISBN);
    }
}