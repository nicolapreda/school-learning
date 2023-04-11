public class Nodo <E>{
    private E dato;
    private Nodo<E> prox;

    public Nodo(E dato){
        this.dato = dato;
        prox = null;
    }

    public E getDato(){
        return dato;
    }

    public Nodo<E> getProx(){
        return prox;
    }

    public void setProx(Nodo<E> nextLink){
        this.prox = nextLink;
    }

    public String toString(){
        return dato.toString();
    }

}

