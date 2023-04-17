public class NodoA {
    private int dato;
    private NodoA figlioSX;
    private NodoA figlioDX;

    public NodoA(int dato) {
        this.dato = dato;
        figlioSX = null;
        figlioDX = null;
    }

    public int getDato() {
        return dato;
    }

    public void SetDato(int dato) {
        this.dato = dato;
    }

    public void setFiglioSX(int elemento) {
        NodoA nodo = new NodoA(elemento);
        figlioSX = nodo;
    }

    public void setFiglioDX(int elemento) {
        NodoA nodo = new NodoA(elemento);
        figlioDX = nodo;
    }

    public NodoA getFiglioSX() {
        return figlioSX;
    }

    public NodoA getFiglioDX() {
        return figlioDX;
    }

    public String toString() {
        return String.valueOf(dato);
    }
}

