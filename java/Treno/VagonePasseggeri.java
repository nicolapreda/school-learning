package Treno;

public class VagonePasseggeri extends Vagone {
    private String classe;
    private int postiDisponibili;
    private int postiOccupati;
    private static final int PESO_OCCUPANTE = 65;

    public String getClasse() {
        return classe;
    }

    public void setClasse(String classe) {
        this.classe = classe;
    }

    public int getPostiDisponibili() {
        return postiDisponibili;
    }

    public void setPostiDisponibili(int postiDisponibili) {
        this.postiDisponibili = postiDisponibili;
    }

    public int getPostiOccupati() {
        return postiOccupati;
    }

    public void setPostiOccupati(int postiOccupati) {
        this.postiOccupati = postiOccupati;
    }

    public int pesoOccupanti() {
        return postiOccupati * PESO_OCCUPANTE;
    }
}
