public class AlberoBinario {
    
    private NodoAlbero radice;
    
    public AlberoBinario(NodoAlbero radice) {
        this.radice = radice;
    }
    
    public NodoAlbero getRadice() {
        return radice;
    }

    public void visualizza(NodoAlbero x){
        if (x.getSinistro()!=null)
            visualizza(x.getSinistro());
        if (x.getDestro()!=null)
            visualizza(x.getDestro());


    }


    private int max = 1;
    private int temp = 1;

    private void getHeight(NodoAlbero NodoAlbero)
    {
        if (NodoAlbero.getSinistro() != null)
        {
            temp++;
            if(temp > max){
                max = temp;
            }
            getHeight(NodoAlbero.getSinistro());
        }
        else
        {
            temp--;
        }

        if (NodoAlbero.getDestro() != null)
        {
            temp++;
            if(temp > max){
                max = temp;
            }
            getHeight(NodoAlbero.getDestro());
        }
        else
        {
            temp--;
        }
    }

    String path;
    public void showBinPath(){
        
        if(radice == null){
            return;
        }else{
            System.out.println(radice.getValore() + " -> root");
            // left
            path(radice.getSinistro(),"0");

            // right
            path(radice.getDestro(),"1");


        }
    }
    
    private void path(NodoAlbero n, String bin){
        System.out.println(n.getValore() + " -> " + bin);
        
        if(n.getSinistro() != null){
            path(n.getSinistro(), bin + "0");
        }
        
        if(n.getDestro() != null){
            path(n.getDestro(), bin + "1");
        }
        
    }
    private boolean found = false;
    
    public boolean find(int n){
        search(radice, n);
        if(found == true){
            found = false;
            return true;
        }
        return false;
    }

    private void search(NodoAlbero point, int n){
        if(point != null){
            if(point.getValore() == n){
                found = true;
            }else{
                if(point.getSinistro() != null){
                    search(point.getSinistro(), n);
                }
                if(point.getDestro() != null){
                    search(point.getDestro(), n);
                }
            }
        }else{
            return;
        }
    }

    
    public void aggiungi(int n){
        NodoAlbero N=new NodoAlbero(n);
        NodoAlbero scorri=radice;
        if (scorri==null)
            radice=N;
        while(scorri!=null){
            if (n<scorri.getValore()){
                if(scorri.getSinistro()==null){
                    scorri.setSinistro(N);
                    scorri=null;
                    }
                else
                    scorri=scorri.getSinistro();
            }
            else{
                if(scorri.getDestro()==null){
                    scorri.setDestro(N);
                    scorri=null;
                }
                else
                    scorri=scorri.getDestro();
            }
        }


    }
}