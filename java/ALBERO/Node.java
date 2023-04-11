public class Node{
   
    private int info;
    private int len;
    private Node sx;
    private Node dx;

    public Node(){
        info = 0;
        sx = null;
        dx = null;
    }

    public Node(int info){
        this.info = info;
        sx = null;
        dx = null;
    }

    public void setInfo(int info) {
        this.info = info;
    }

    public int getInfo() {
        return info;
    }

    public void setSx(Node sx) {
        this.sx = sx;
    }

    public Node getSx() {
        return sx;
    }
    
    public void setDx(Node dx) {
        this.dx = dx;
    }

    public Node getDx() {
        return dx;
    }

    public int getLen() {
        return len;
    }
    
    public void setLen(int len) {
        this.len = len;
    }
}