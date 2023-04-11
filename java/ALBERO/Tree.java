public class Tree {

    private Node root;
    private int elements;

    public Tree(Node root){
        this.root = root;
        elements = 1;
    }

    public void AddNode(Node n){
        
        if(root == null){
            root = n;
            elements++;
        }else{
            Node temp = root;
            while(temp != null){   //temp.getSx() == null && n.getInfo() < temp.getInfo() || temp.getDx() == null && n.getInfo >= temp.getInfo()
                if(n.getInfo() < temp.getInfo()){
                    if(temp.getSx() == null){
                        temp.setSx(n);
                        temp = null;
                    }else{
                        temp = temp.getSx();
                    }
                }else{
                    if(temp.getDx() == null){
                        temp.setDx(n);
                        temp = null;
                    }else{
                        temp = temp.getDx();
                    }
                }
            }
            elements++;
        }
    }

    public void AddInfo(int n){
        Node N = new Node(n);

        if(root == null){
            root = N;
            elements++;
        }else{
            Node temp = root;
            while(temp != null){   //temp.getSx() == null && n.getInfo() < temp.getInfo() || temp.getDx() == null && n.getInfo >= temp.getInfo()
                if(N.getInfo() < temp.getInfo()){
                    if(temp.getSx() == null){
                        temp.setSx(N);
                        temp = null;
                    }else{
                        temp = temp.getSx();
                    }
                }else{
                    if(temp.getDx() == null){
                        temp.setDx(N);
                        temp = null;
                    }else{
                        temp = temp.getDx();
                    }
                }
            }
            elements++;
        }
    }

    public void showInOrder(Node n){
        if(n.getSx() != null){
            showInOrder(n.getSx());
        }
        if (n.getDx() != null){
            showInOrder(n.getDx());  
        }
    }


    
    // ALTEZZA
    private int max = 1;
    private int temp = 1;

    public int getHeight()
    {
        if (root == null)
        {
            return 0;
        }
        else
        {
            if(root.getSx() != null){
                getHeight(root.getSx());
            }
            if(root.getDx() != null){
                getHeight(root.getDx());
            }
        }

        return max+1;
    }

    private void getHeight(Node node)
    {
        if (node.getSx() != null)
        {
            temp++;
            if(temp > max){
                max = temp;
            }
            getHeight(node.getSx());
        }
        else
        {
            temp--;
        }

        if (node.getDx() != null)
        {
            temp++;
            if(temp > max){
                max = temp;
            }
            getHeight(node.getDx());
        }
        else
        {
            temp--;
        }
    }


    // ALBERO BILANCIATO

    private int array[];
    private int index = 0;
    
    public void bilance()
    {
        if (root == null)
        {
            return;
        }
        else
        {
            if(root.getSx() != null){
                searchCount(root.getSx());
            }
            if(root.getDx() != null){
                searchCount(root.getDx());
            }
        }
        index = 0;
        bubbleSort(array);
        

        return;
    }

    private void searchCount(Node node)
    {
        if (node.getSx() != null)
        {
            array[index] = node.getSx().getInfo();
            index++;
        
            searchCount(node.getSx());
        }

        if (node.getDx() != null)
        {
            array[index] = node.getDx().getInfo();
            index++;

            searchCount(node.getDx());
        }
    
    }

    public void bubbleSort(int [] arr) {
        for(int i = 0; i < arr.length; i++) {
            boolean flag = false;
            for(int j = 0; j < arr.length-1; j++) {
                if(array[j]>arr[j+1]) {
                    int k = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = k;
                    flag=true; //Lo setto a true per indicare che é avvenuto uno scambio
                }
            }
            if(!flag) break;
        }
    }


    // FUNZIONE RICERCA
    private boolean found = false;
    
    public boolean find(int n){
        search(root, n);
        if(found == true){
            found = false;
            return true;
        }
        return false;
    }

    private void search(Node point, int n){
        if(point != null){
            if(point.getInfo() == n){
                found = true;
            }else{
                if(point.getSx() != null){
                    search(point.getSx(), n);
                }
                if(point.getDx() != null){
                    search(point.getDx(), n);
                }
            }
        }else{
            return;
        }
    }

    // COSTRUIRE PATH BINARIO
    String path;
    public void showBinPath(){
        
        if(root == null){
            return;
        }else{
            System.out.println(root.getInfo() + " -> root");
            // left
            path(root.getSx(),"0");

            // right
            path(root.getDx(),"1");

        }
    }
    
    private void path(Node n, String bin){
        System.out.println(n.getInfo() + " -> " + bin);
        
        if(n.getSx() != null){
            path(n.getSx(), bin + "0");
        }
        
        if(n.getDx() != null){
            path(n.getDx(), bin + "1");
        }
        
    }



}