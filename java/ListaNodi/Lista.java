public class Lista<E> {

    private Nodo<E> testa;
    private Nodo<E> coda;

    private int e;

    public Lista(Nodo<E> n){
        testa = n;
        coda = n;
        e = 1;
    }
    public void aggiungiInTesta(Nodo<E> n){
        n.setProx(testa);
        testa = n;
        e++;
    }
    public void aggiungiInCoda(Nodo<E> n){
        coda.setProx(n);
        coda = n;
        e++;
    }

    public String toString(){
        String stringa = "";
        if(testa != null){
            Nodo<E> p = testa;
            while(p != null){
                stringa +=p.toString() + " ";
                p = p.getProx();
            }
        }
        return stringa;
    }
}
