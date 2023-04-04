public class Pila {
    private Form pilaFrazione[];
    private int elementi; // numero degli elementi presenti nella pila

    public Pila(int max) {
        pilaFrazione = new Form[max];
        elementi = 0;
    }

    public Form pop() {
        if (isEmpty())
            return null;
            Form temp = pilaFrazione[elementi - 1];
        elementi--;
        pilaFrazione[elementi] = null;
        return temp;
    }

    public void push(Form libro) {
        if (elementi == pilaFrazione.length)
            return;
        pilaFrazione[elementi] = libro;
        elementi++;
    }

    public Form top() {
        return pilaFrazione[elementi - 1];
    }

    public int size() {
        return elementi;
    }

    public boolean isEmpty() {
        if (elementi == 0)
            return true;
        return false;
    }
}