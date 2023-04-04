public class Nodo {
    private int dato;
    private Nodo link;
    
    public Nodo(int dato) {
        this.dato = dato;
        link = null;
        //indica che non c'è un successivo
    }
    
    public int getDato() {
        return this.dato;
    }
    
    public Nodo getLink() {
        return this.link;
    }
    
    public void setLink(Nodo successivo) {
        this.link = successivo;
    }
}
