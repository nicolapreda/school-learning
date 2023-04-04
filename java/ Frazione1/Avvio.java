import java.util.Scanner;

public class Avvio
{
    // variabili d'istanza - sostituisci l'esempio che segue con il tuo
    public static void main (String[] args){
    
        Frazione f = new Frazione(2,3);         
        Scanner scelta=new Scanner(System.in); // varibile "scanner" puntatore
        int s; // scelta dell'utente
        do{
            Scanner sc=new Scanner(System.in);
            int comando=sc.nextInt();
            switch(comando){      
                case 1: 
                    f.getNum();
                    break;
                case 2:
                    f.getDen();
                    break;
                case 3:
                    f.setNum(2);
                    break;
                case 4:
                    f.setDen(2);
                    break;
                case 5:
                    f.somma(f);
                    break;
                case 6:
                    f.sottrai(f);
                    break;
                case 7:
                    f.diviso(f);
                    break;
                case 8:
                    f.toString();
                    break;
                case 9:
                    f.riduci();
                    break;
                case 10:
                    f.valore();
                    break;
                case 11:
                    f.equals(f);
                    break;
                case 12:
                    f.maggiore(f);
                    break;
                case 13:
                    f.minore(f);
                    break;
            }
            System.out.println("Digita 0 se vuoi continuare altrimento digita 1");
            s=scelta.nextInt();
            while(s!=1 && s!=0){
                s=scelta.nextInt();
            }
            //System.out.println("Inserisci 1 se vuoi terminare, altrimenti 0, se vuoi continuare");
        }while(s==0);
        }
        
}
