import java.util.Scanner;

 
public class LancioTele extends Telecomando {

    public static void main(String[] args) {
        Telecomando auto = new Telecomando();
        
        Scanner sc=new Scanner(System.in);    
        
        int comando;
        
        do{
            System.out.print('\u000c');
            System.out.println("Inserisci un comando");
            System.out.println("1 => Accendi");
            System.out.println("2 => Cambia canale");
            System.out.println("3 => Aumenta volume");
            System.out.println("4 => Diminuisci volume");
            System.out.println("5 => Aumenta luminosità");
            System.out.println("6 => Diminuisci luminosità");
            System.out.println("7 => Spegni ");
            System.out.println("8 => Esci ");
   
            comando = sc.nextInt();

            switch(comando){
                case 1:
                    auto.accendi();
                    break;
                case 2:
                    auto.cambiaCanale();
                    break;
                case 3:
                    auto.aumentaVolume();
                    break;
                case 4:
                    auto.diminuisciVolume();
                    break;
                case 5:
                    auto.aumentaLuminosita();
                    break;
                case 6:
                    auto.diminuisciLuminosita();
                    break;
                case 7:
                    auto.spegni();
                    break;
                case 8:
                    System.out.println("Arrivederci");
                    break;
                default:
                    System.out.println("Comando non valido");
            }

            System.out.println("Premi invio per continuare...");
            String continua=sc.nextLine();
            continua=sc.nextLine();
            
   
        }
        while(comando!=8);

    }
}
