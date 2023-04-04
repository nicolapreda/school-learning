public class Nodo {
    
    private int dato; //parte informativa del nodo
    private Nodo link; //riferimento al nodo successivo
    
    public Nodo(int dato) {
        this.dato=dato;
        link=null;
    }
    
    /*
    public Nodo(int dato, Nodo link){ // solo per inserire in testa
        this.dato = dato;
        this.link = link;
    }
    */
   
    public int getDato() {
        return dato;
    }
    
    public void setDato(int dato){
        this.dato=dato;
    }
    
    public Nodo getLink() {
        return link;
    }
    
    public void setLink(Nodo link){
        this.link=link;
    }

}
