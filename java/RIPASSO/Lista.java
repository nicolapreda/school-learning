public class Lista {
    
    private Nodo head; //il nodo in testa alla lista
    private int count; //numero degli elementi nella lista
    private Nodo tail;
    
    public Lista() {
        head=null;
        tail=null;
        count=0;
    }
    
    public Lista(Nodo n){
        head = n;
        count = conta();
    }
    
    private int conta(){
        Nodo pn = head;
        
        if(head == null)
            return 0;
        count = 1;
        
        while(pn.getLink() != null){
            count++;
            pn = pn.getLink(); // vai al nodo successivo
        }
        tail = pn; // abbiamo trovato la coda
        return count;
    }
    
    public void aggiungiInTesta(Nodo n){
        if(tail == null){
            tail = n;
        }
        n.setLink(head);
        head = n;
        count++;
    }
    
    public int getCount(){
        return count;
    }
    
    public void aggiungiInCoda(Nodo n){
        if(tail == null){
            aggiungiInTesta(n);
        }
        else{
            tail.setLink(n);
            tail = n;
            count++;
        }
    }
    
    public void aggiungiInOrdine(Nodo n){
        if(head == null){
            aggiungiInTesta(n);
        }
        else if(n.getDato() < head.getDato()){
            aggiungiInTesta(n);
        }
        else if(n.getDato() > tail.getDato()){
            aggiungiInCoda(n);   
        }
        else{
            Nodo pp = head;
            Nodo ps = head.getLink();
            while(ps.getDato() <= n.getDato()){
                pp = ps;
                ps = ps.getLink();
            }
            n.setLink(ps);
            pp.setLink(n);
            count++;
        }
    }    
    
    public void visualizza(){
        Nodo temp = head;
        while(temp != null){
            System.out.println(temp.getDato());
            temp = temp.getLink();
        }
    }
    
    public void eliminaInTesta(){
        if(head == null){
            return;
        }
        head = head.getLink();
        count--;
    }
    
    public void eliminaInCoda(){
        Nodo pp = head;
        Nodo ps = head;
        
        if(head == null){
            return;
        }
        if(count == 1){
            head = head.getLink();
            count--;
        }
        else{
            while(pp.getLink() != null){ // scorro la lista
                pp = ps;
                ps = ps.getLink();
            }
            pp.setLink(null);  
            count--;
        }
    }
    
    
}
