public class Main{
    public static void main(String args[]){

        Lista<Integer> lista = new Lista<Integer>(new Nodo<Integer>(7));
        lista.aggiungiInTesta(new Nodo<Integer>(9));
        lista.aggiungiInTesta(new Nodo<Integer>(10));
        lista.aggiungiInTesta(new Nodo<Integer>(12));
        lista.aggiungiInTesta(new Nodo<Integer>(15));
        lista.aggiungiInTesta(new Nodo<Integer>(-9));
        lista.aggiungiInCoda(new Nodo<Integer>(-15));


        System.out.println(lista.toString());

    }
}
