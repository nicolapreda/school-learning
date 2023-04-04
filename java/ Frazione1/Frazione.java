import java.util.Scanner; // libreria per la classe Scanner

public class Frazione
{
    // variabili d'istanza - sostituisci l'esempio che segue con il tuo
    private int num;
    private int den;
    
    // costruttore senza parametri che inizializza a 0 il numeratore e a 1 il denominatore
    public Frazione(){
        this.num=num;
        this.den=den;
        num=0;
        den=1;
    }
    
    // costruttore che riceve come solo parametro il numeratore
    public Frazione(int num){
        this.num=num;
        this.den=den;
        den=1;
    }
    
    // costruttore che riceve come parametri il numeratore e il denominatore    
    public Frazione(int num, int den){
        this.num=num;
        this.den=den;
        if(den == 0){
            den=1;
        }
    }

        
    // Implementazione dei metodi
    public int getNum(){
       return num;
    }
    public int getDen(){
        return den;
    }
    public void setNum(int num){
        this.num=num;
    }
    public void setDen(int den){
        this.den = den;
    }
    public Frazione somma(Frazione f){
        int n = this.num * f.den + this.den * f.num;
        int d = this.den * f.den;
        return new Frazione(n, d);
    }
    public Frazione sottrai(Frazione f){
         int n = this.num * f.den - this.den * f.num;
         int d = this.den * f.den;
         return new Frazione(n, d);
    }
    public Frazione per(Frazione f){
        int n = this.num * f.num;
        int d = this.den * f.den;
        return new Frazione(n, d);
    }
    public Frazione diviso(Frazione f){
        int n = this.num * f.den;
        int d = this.den * f.num;
        return new Frazione(n, d);
    }
    public String toString(){
        if (den == 0)
            return "Impossibile";
        else if (den == 1)
            return String.valueOf(num);
        else
            return num + "/" + den;
    }
    private int mcm(int num, int den){
        if(den == 0){
            return num;
        }
        else{
            return mcm(den, num%den);
        }
    }
    public void riduci(){
        int m=mcm(num,den);
        while(mcm(num,den)!=1){
            int numeratore = num/m;
            int denominatore = den/m;
            this.num=numeratore;
            this.den=denominatore;
        }
        if(num!=den || (num>0 && den==1)){
            System.out.println(num);
        }
        else{
            System.out.println(num + "/" + den);            
        }
    }
    public double valore(){
        double val = num/den;
        return val;
    }
    public boolean equals(Frazione f){
        if (this.num == f.num && this.den == f.den)
            return true;
        else
            return false;
    }
    public boolean maggiore(Frazione f){
        Frazione g = this.sottrai(f);
        if (g.num>0){
            return true;
        }
        else{
            return false;
        }
    }
    public boolean minore(Frazione f){
        Frazione g = this.sottrai(f);
        if (g.num<0){
            return true;
        }
        else{
            return false;
        }
    }
}
