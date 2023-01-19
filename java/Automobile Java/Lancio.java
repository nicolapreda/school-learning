import java.util.Scanner;

 
public class Lancio {

    public Lancio() {
    }

    public static void main(String[] args) {
        Automobile auto = new Automobile("Maserati", "Panda", 3000);
        
        Scanner sc=new Scanner(System.in);    
        
        int comando;
        
        do{
            System.out.print('\u000c');
            System.out.println("Inserisci un comando");
            System.out.println("1 => Avvia motore");
            System.out.println("2 => Cambia marcia");
            System.out.println("3 => Accelera");
            System.out.println("4 => Frena");
            System.out.println("5 => Spegni il motore");
            System.out.println("6 => Riempi il serbatoio");
            System.out.println("7 => Mostra lo stato dell'automobile ");
            System.out.println("8 => Esci ");
   
            comando = sc.nextInt();

            switch(comando){
                case 1:
                    auto.avviaMotore();
                    break;
                case 2:
                    System.out.println("Vuoi aumentare(1) o diminuire(0) la marcia? ");
                    comando=sc.nextInt();
                    if(comando == 1)
                        auto.saliMarcia();

                    else if(comando == 1)
                        auto.saliMarcia();
                    else if(comando == 0)
                        auto.scendiMarcia();
                    break;
                case 3:
                    auto.accelera();
                    break;
                case 4:
                    auto.frena();
                    System.out.println("Frenata effettuata");

                    break;
                case 5:
                    auto.ferma();
                    break;
                case 6:
                    System.out.println("Quanto vuoi riempire il serbatoio? ");
                    comando=sc.nextInt();
                    auto.riempi(comando);
                    break;
                case 7:
                    auto.mostraStato();
                    break;
                case 8:
                    System.out.println("bye :)");
                    break;
                default:
                    System.out.println("Comando non valido");
                    break;

        


            }
               
            System.out.println("Premi invio per continuare...");
            String continua=sc.nextLine();
            continua=sc.nextLine();
            
   
        }
        while(comando!=8);

    }
}
