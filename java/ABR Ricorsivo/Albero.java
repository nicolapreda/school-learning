public class Albero {
    private NodoA radice; // il nodo radice dell’albero

    public Albero() {
        radice = null;
    }

    public NodoA getRadice() {
        return radice;
    }

    public void insert(int dato) {
        radice = insertRicorsivo(radice, dato);
    }

    private NodoA insertRicorsivo(NodoA nodo, int dato) {
        if (nodo == null) {
            return new NodoA(dato);
        }
        if (dato < nodo.getDato()) {
            nodo.setFiglioSX(insertRicorsivo(nodo.getFiglioSX(), dato));
        } else if (dato > nodo.getDato()) {
            nodo.setFiglioDX(insertRicorsivo(nodo.getFiglioDX(), dato));
        }
        return nodo;
    }
    
    public NodoA search(int dato) {
        return searchRicorsivo(radice, dato);
    }
    
    private NodoA searchRicorsivo(NodoA nodo, int dato) {
        if (nodo == null || nodo.getDato() == dato) {
            return nodo;
        }
        if (dato < nodo.getDato()) {
            return searchRicorsivo(nodo.getFiglioSX(), dato);
        }
        return searchRicorsivo(nodo.getFiglioDX(), dato);
    }
    
}