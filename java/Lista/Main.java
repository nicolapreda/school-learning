public class Main {
    public static void main(String[] args) {
        Lista lista = new Lista();
        lista.inserisciNodoInCoda(new Nodo(1));
        lista.inserisciNodoInCoda(new Nodo(2));
        lista.inserisciNodoInCoda(new Nodo(3));
        
        lista.visitaIterativa();
        
        lista.cancellaNodoInCoda();
        lista.visitaIterativa();
    }
}
