class Campana extends dindondan implements Runnable{
String suono;
int volte;
public Campana (String suono, int volte) {
    this.suono = suono;
    this.volte = volte;
}

public void run () {
    for (int k = 0; k < volte; k++) {
        System.out.println(( k + 1) +suono+" ");
    }
}
}