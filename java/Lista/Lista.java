public class Lista {
    private Nodo head;
    private Nodo tail;
    private int count;

    public Lista() {
        head = null;
        tail = null;
        count = 0;
    }

    public Lista(Nodo n){
        head = n;
    }

    private void conta(){
        Nodo temp = head;
        if(head == null){
            return;
        }
        count = 1;
        while(temp.getLink() != null){
            count++;
            temp = temp.getLink();
        }
        tail = temp;

    }
    
    private void aggiungiInOrdine(Nodo n){
        if(n.getDato() < head.getDato()){
            aggiungiInOrdine(n);
        }
        else if(n.getDato() > tail.getDato()){
            aggiungiInOrdine(n);
        }
        else{
            Nodo pp = head;
            Nodo ps = head.getLink();
            while(ps.getDato() < n.getDato()){
                pp = ps;
                ps = ps.getLink();
            }
            n.setLink(ps);
            pp.setLink(n);
            count++;
        }
        }


    public int getCount(){
        return count;
    }
    
    public void visitaIterativa() {
        Nodo nodoCorrente = this.head;
        while(nodoCorrente != null) {
            System.out.println(nodoCorrente.getDato());
            nodoCorrente = nodoCorrente.getLink();
        }
    }
    
    public void cancellaNodoInCoda() {
        if(this.head == null) {
            return;
        }
        if(this.head.getLink() == null) {
            this.head = null;
            return;
        }
        Nodo nodoCorrente = this.head;
        while(nodoCorrente.getLink().getLink() != null) {
            nodoCorrente = nodoCorrente.getLink();
        }
        nodoCorrente.setLink(null);
    }
    
    public void inserisciNodoInCoda(Nodo nuovoNodo) {
        if(this.head == null) {
            this.head = nuovoNodo;
            return;
        }
        Nodo nodoCorrente = this.head;
        while(nodoCorrente.getLink() != null) {
            nodoCorrente = nodoCorrente.getLink();
        }
        nodoCorrente.setLink(nuovoNodo);
    }
}
