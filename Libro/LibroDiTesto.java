public class LibroDiTesto extends Libro {
    private String materia;
    private boolean adozione;

    public LibroDiTesto(String materia, boolean adozione, String autore, String titolo, int numeroPagine, String codiceISBN){
        super(autore, titolo, numeroPagine, codiceISBN);
        this.materia = materia;
        this.adozione = adozione;
    }
    
    public void setmateria(String materia){
        this.materia = materia;
    }

    public String getmateria(){
        return materia;
    }

    public void cambiaadozione(){
        if(adozione == true){
            adozione = false;
        } else {
            adozione = true;
        }
    }

}