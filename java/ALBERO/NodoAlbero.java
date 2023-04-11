class NodoAlbero {
    
    private int valore;
    private NodoAlbero sinistro;
    private NodoAlbero destro;

public NodoAlbero(int valore) {
    this.valore = valore;
    this.sinistro = null;
    this.destro = null;
}

public int getValore() {
    return valore;
}

public NodoAlbero getSinistro() {
    return sinistro;
}

public NodoAlbero getDestro() {
    return destro;
}

public void setSinistro(NodoAlbero sinistro) {
    this.sinistro = sinistro;
}

public void setDestro(NodoAlbero destro) {
    this.destro = destro;
}
}
