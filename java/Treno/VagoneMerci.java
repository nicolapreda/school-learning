package Treno;


public class VagoneMerci extends Vagone {
    private int volumeCarico;
    private int pesoMassimoCarico;
    private int pesoEffettivoCarico;
    public int getPesoEffettivoCarico() {
        return pesoEffettivoCarico;
    }
    public int volumeCarico() {
        return volumeCarico;
    }
    public int pesoMassimoCarico() {
        return pesoMassimoCarico;
    }
    public void setPesoEffettivoCarico(int pesoEffettivoCarico) {
        this.pesoEffettivoCarico = pesoEffettivoCarico;
    }
    public void setVolumeCarico(int volumeCarico) {
        this.volumeCarico = volumeCarico;
    }
    public void setPesoMassimoCarico(int pesoMassimoCarico) {
        this.pesoMassimoCarico = pesoMassimoCarico;
    }


}
