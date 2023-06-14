public class Lancio {
    public static void main(String[] args) {
        // creazione dell'albero binario di esempio
        NodoAlbero radice = new NodoAlbero(10);
        
        radice.setSinistro(new NodoAlbero(5));
        radice.setDestro(new NodoAlbero(15));
        radice.getSinistro().setSinistro(new NodoAlbero(2));
        radice.getSinistro().setDestro(new NodoAlbero(7));
        radice.getSinistro().getSinistro().setDestro(new NodoAlbero(3));
        radice.getSinistro().getDestro().setSinistro(new NodoAlbero(6));
        
        AlberoBinario albero = new AlberoBinario(radice);
    
        albero.aggiungi(5);
        albero.aggiungi(15);
        albero.aggiungi(2);
 
        
        //visualizzo testuale
        albero.visualizza(albero.getRadice());
        // visualizzazione dell'albero
        new AlberoBinarioFrame(albero);

    }
}
