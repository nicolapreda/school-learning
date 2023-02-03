package Treno;

import java.util.ArrayList;
import java.util.List;

public class Treno {
    private List<Vagone> vagoni;
    public Treno() {
        vagoni = new ArrayList<Vagone>();
    }

    public void aggiungiVagone(Vagone vagone) {
        vagoni.add(vagone);
    }

    public int pesoComplessivo() {
        int peso = 0;
        for (Vagone vagone : vagoni) {
            peso += vagone.getPesoVuoto();
            if (vagone instanceof VagonePasseggeri) {
                peso += ((VagonePasseggeri) vagone).pesoOccupanti();
            } else if (vagone instanceof VagoneMerci) {
                peso += ((VagoneMerci) vagone).getPesoEffettivoCarico();
            }
        }
        return peso;
    }
}
