
public class Lista {
    private Node head;
    private Node tail;
    private int size;

    public Lista(int[] arr) {
        this.size = arr.length;
        for (int i = arr.length - 1; i >= 0; i--) {
            addFirst(arr[i]);
        }
    }

    public int shuffle(int k, int h) {
        // Verifica che k e h siano all'interno dei limiti della lista
        if (k < 0 || k >= size || h < 0 || h >= size) {
            return -1; // Restituisce -1 se uno dei parametri è fuori dai limiti
        }
        
        // Se k == h, non c'è bisogno di fare nulla
        if (k == h) {
            return 0; // Restituisce 0 per indicare che non è stato fatto nessun spostamento
        }
        
        // Estrae il nodo corrispondente all'elemento in posizione k
        Node node = getNodeAt(k);
        removeNode(node);
        
        // A seconda del valore di h, aggiunge il nodo nella posizione desiderata
        if (h == 0) {
            // Se h == 0, l'elemento va messo in testa alla lista
            addFirst(node.getValue());
        } else if (h == size - 1) {
            // Se h == size - 1, l'elemento va messo in coda alla lista
            addLast(node.getValue());
        } else {
            // Altrimenti, l'elemento va messo prima del nodo in posizione h
            Node targetNode = getNodeAt(h);
            addBefore(targetNode, node.getValue());
        }
        
        // Restituisce 1 per indicare che l'operazione è stata eseguita con successo
        return 1;
    }
    


    public void lastFirst() {
        if (size <= 1) {
            return;
        }

        Node lastNode = tail;
        Node secondToLastNode = getNodeAt(size - 2);
        Node firstNode = head;

        // rimuovi l'ultimo nodo dalla lista
        removeNode(lastNode);

        // sposta il primo nodo alla fine della lista
        removeNode(firstNode);
        addLast(firstNode.getValue());

        // sposta l'ultimo nodo all'inizio della lista
        addFirst(lastNode.getValue());
    }

    // restituisce il nodo in posizione index
    private Node getNodeAt(int index) {
        if (index < 0 || index >= size) {
            return null;
        }

        Node currNode = head;
        for (int i = 0; i < index; i++) {
            currNode = currNode.getNext();
        }
        return currNode;
    }

    // rimuove il nodo dalla lista
    private void removeNode(Node node) {
        if (node == null) {
            return;
        }

        if (node == head) {
            head = node.getNext();
        } else {
            Node prevNode = head;
            while (prevNode.getNext() != node) {
                prevNode = prevNode.getNext();
            }
            prevNode.setNext(node.getNext());
        }

        if (node == tail) {
            tail = node.getPrev();
        } else {
            Node nextNode = node.getNext();
            nextNode.setPrev(node.getPrev());
        }

        node.setNext(null);
        node.setPrev(null);
        size--;
    }

    // rimuove il nodo in posizione index dalla lista
    private void removeNodeAt(int index) {
        Node nodeToRemove = getNodeAt(index);
        removeNode(nodeToRemove);
    }

    // aggiunge il valore alla fine della lista
    private void addLast(int value) {
        Node newNode = new Node(value);
        if (tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.setPrev(tail);
            tail.setNext(newNode);
            tail = newNode;
        }
        size++;
    }

    // aggiunge il valore all'inizio della lista
    private void addFirst(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.setNext(head);
            head.setPrev(newNode);
            head = newNode;
        }
        size++;
    }

    // aggiunge il valore prima del nodo specificato
    private void addBefore(Node node, int value
    ) {
        if (node == null) {
        return;
        }
        
        Node newNode = new Node(value);
        newNode.setPrev(node.getPrev());
        newNode.setNext(node);
        if (node == head) {
            head = newNode;
        } else {
            Node prevNode = node.getPrev();
            prevNode.setNext(newNode);
        }
        node.setPrev(newNode);
    
        size++;
    }
    
    // rappresentazione testuale della lista
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        Node currNode = head;
        while (currNode != null) {
            sb.append(currNode.getValue());
            if (currNode.getNext() != null) {
                sb.append(", ");
            }
            currNode = currNode.getNext();
        }
        sb.append("]");
        return sb.toString();
    }
    
    // nodo interno della lista
    private static class Node {
        private int value;
        private Node prev;
        private Node next;
    
        public Node(int value) {
            this.value = value;
        }
    
        public int getValue() {
            return value;
        }
    
        public void setValue(int value) {
            this.value = value;
        }
    
        public Node getPrev() {
            return prev;
        }
    
        public void setPrev(Node prev) {
            this.prev = prev;
        }
    
        public Node getNext() {
            return next;
        }
    
        public void setNext(Node next) {
            this.next = next;
        }
    }
}

            