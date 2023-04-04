import java.util.Scanner;

public class APP
{
    public static void main(String args[])
    {
        Lista l = new Lista();
        l.aggiungiInCoda(new Nodo(0));
        l.aggiungiInCoda(new Nodo(10));
        l.aggiungiInCoda(new Nodo(20));
        l.aggiungiInCoda(new Nodo(30));
        
        l.aggiungiInOrdine(new Nodo(15));
        //l.visualizza();
        
        System.out.println("Inserisci 1 per terminare");
        Scanner sc = new Scanner(System.in);
        int dato = sc.nextInt();
        
        while(dato != 1){
            l.aggiungiInOrdine(new Nodo(dato));
            dato = sc.nextInt();
        }
        
        l.visualizza();
       
    }
}
